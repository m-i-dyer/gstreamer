/* GStreamer Intel MSDK plugin
 * Copyright (c) 2016, Oblong Industries, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __GST_MSDKH265ENC_H__
#define __GST_MSDKH265ENC_H__

#include "gstmsdkenc.h"
#include <gst/codecparsers/gsth265parser.h>

G_BEGIN_DECLS

#define GST_TYPE_MSDKH265ENC \
  (gst_msdkh265enc_get_type())
#define GST_MSDKH265ENC(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),GST_TYPE_MSDKH265ENC,GstMsdkH265Enc))
#define GST_MSDKH265ENC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),GST_TYPE_MSDKH265ENC,GstMsdkH265EncClass))
#define GST_IS_MSDKH265ENC(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),GST_TYPE_MSDKH265ENC))
#define GST_IS_MSDKH265ENC_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),GST_TYPE_MSDKH265ENC))

typedef struct _GstMsdkH265Enc GstMsdkH265Enc;
typedef struct _GstMsdkH265EncClass GstMsdkH265EncClass;

struct _GstMsdkH265Enc
{
  GstMsdkEnc base;

  gchar *profile_name;
  gboolean lowpower;
  gushort num_tile_rows;
  gushort num_tile_cols;
  guint max_slice_size;
  gint tune_mode;
  guint prop_flag;
  gushort transform_skip;
  guint b_pyramid;
  guint p_pyramid;
  guint min_qp;
  guint max_qp;
  guint intra_refresh_type;
  guint intra_refresh_cycle_size;
  gint intra_refresh_qp_delta;
  guint intra_refresh_cycle_dist;
  guint dblk_idc;

  mfxExtHEVCTiles ext_tiles;
  mfxExtHEVCParam ext_param;
  /* roi[0] for current ROI and roi[1] for previous ROI */
  mfxExtEncoderROI roi[2];

  GstH265Parser *parser;
  GArray *cc_sei_array;
};

struct _GstMsdkH265EncClass
{
  GstMsdkEncClass parent_class;
};

GType gst_msdkh265enc_get_type (void);

G_END_DECLS

#endif /* __GST_MSDKH265ENC_H__ */
