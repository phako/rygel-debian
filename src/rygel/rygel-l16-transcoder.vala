/*
 * Copyright (C) 2009 Nokia Corporation.
 *
 * Author: Zeeshan Ali (Khattak) <zeeshanak@gnome.org>
 *                               <zeeshan.ali@nokia.com>
 *
 * This file is part of Rygel.
 *
 * Rygel is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Rygel is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */
using Gst;
using GUPnP;
using Gee;

internal enum Endianness {
    LITTLE = ByteOrder.LITTLE_ENDIAN,
    BIG = ByteOrder.BIG_ENDIAN
}

/**
 * Transcoder for linear PCM audio (LPCM). This element uses L16TrancoderBin for
 * actual transcoding.
 */
internal class Rygel.L16Transcoder : Rygel.Transcoder {
    private const int CHANNELS = 2;
    private const int FREQUENCY = 44100;
    private const int WIDTH = 16;
    private const int DEPTH = 16;
    private const bool SIGNED = true;

    private Endianness endianness;

    private const string AUDIO_CONVERT = "audioconvert";
    private const string AUDIO_RESAMPLE = "audioresample";
    private const string AUDIO_RATE = "audiorate";
    private const string CAPS_FILTER = "capsfilter";

    public L16Transcoder (Endianness endianness) {
        var mime_type = "audio/L" + L16Transcoder.WIDTH.to_string () +
                        ";rate=" + L16Transcoder.FREQUENCY.to_string () +
                        ";channels=" + L16Transcoder.CHANNELS.to_string ();

        base (mime_type, "LPCM", MediaItem.AUDIO_CLASS);

        this.endianness = endianness;
    }

    public override Element create_source (MediaItem item,
                                           Element   src)
                                           throws Error {
        return new L16TranscoderBin (item, src, this);
    }

    public override DIDLLiteResource? add_resource (DIDLLiteItem     didl_item,
                                                    MediaItem        item,
                                                    TranscodeManager manager)
                                                    throws Error {
        var resource = base.add_resource (didl_item, item, manager);
        if (resource == null)
            return null;

        resource.sample_freq = L16Transcoder.FREQUENCY;
        resource.audio_channels = L16Transcoder.CHANNELS;
        resource.bits_per_sample = L16Transcoder.WIDTH;
        // Set bitrate in bytes/second
        resource.bitrate = L16Transcoder.FREQUENCY *
                           L16Transcoder.CHANNELS *
                           L16Transcoder.WIDTH / 8;

        return resource;
    }

    public override uint get_distance (MediaItem item) {
        if (item.upnp_class.has_prefix (MediaItem.IMAGE_CLASS)) {
            return uint.MAX;
        }

        uint distance;

        if (item.upnp_class.has_prefix (MediaItem.AUDIO_CLASS)) {
            distance = uint.MIN;

            if (item.sample_freq > 0) {
                distance += (item.sample_freq - FREQUENCY).abs ();
            }

            if (item.n_audio_channels > 0) {
                distance += (item.n_audio_channels - CHANNELS).abs ();
            }

            if (item.bits_per_sample > 0) {
                distance += (item.bits_per_sample - WIDTH).abs ();
            }
        } else {
            distance = uint.MAX / 2;
        }

        return distance;
    }

    public Element create_encoder (MediaItem item,
                                   string?   src_pad_name,
                                   string?   sink_pad_name)
                                   throws Error {
        dynamic Element convert1 = GstUtils.create_element (AUDIO_CONVERT,
                                                            null);
        dynamic Element resample = GstUtils.create_element (AUDIO_RESAMPLE,
                                                            AUDIO_RESAMPLE);
        dynamic Element audiorate = GstUtils.create_element (AUDIO_RATE, null);
        dynamic Element convert2 = GstUtils.create_element (AUDIO_CONVERT,
                                                            null);
        dynamic Element capsfilter = GstUtils.create_element (CAPS_FILTER,
                                                              CAPS_FILTER);

        var bin = new Bin ("l16-encoder-bin");
        bin.add_many (convert1, resample, audiorate, convert2, capsfilter);

        capsfilter.caps = new Caps.simple (
                                    "audio/x-raw-int",
                                    "channels", typeof (int), CHANNELS,
                                    "rate",  typeof (int), FREQUENCY,
                                    "width", typeof (int), WIDTH,
                                    "depth", typeof (int), DEPTH,
                                    "signed", typeof (bool), SIGNED,
                                    "endianness", typeof (int),
                                    this.endianness);

        convert1.link_many (resample, audiorate, convert2, capsfilter);

        var pad = convert1.get_static_pad ("sink");
        var ghost = new GhostPad (sink_pad_name, pad);
        bin.add_pad (ghost);

        pad = capsfilter.get_static_pad ("src");
        ghost = new GhostPad (src_pad_name, pad);
        bin.add_pad (ghost);

        return bin;
    }
}
