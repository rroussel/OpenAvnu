/****************************************************************************
  Copyright (c) 2015, J.D. Koftinoff Software, Ltd.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

   1. Redistributions of source code must retain the above copyright notice,
      this list of conditions and the following disclaimer.

   2. Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.

   3. Neither the name of J.D. Koftinoff Software, Ltd. nor the names of its
      contributors may be used to endorse or promote products derived from
      this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
  POSSIBILITY OF SUCH DAMAGE.

******************************************************************************/

#include "srp_encoding.h"

void srp_encoding_talker_inc_first_value(struct srp_info_talker *self)
{
	uint64_t stream_id_value =
	    jdksavdecc_eui64_convert_to_uint64(&self->stream_id);
	uint64_t destination_address_value = jdksavdecc_eui48_convert_to_uint64(
	    &self->data_frame_parameters.destination_address);
	stream_id_value++;
	destination_address_value++;
	jdksavdecc_eui64_init_from_uint64(&self->stream_id, stream_id_value);
	jdksavdecc_eui48_init_from_uint64(
	    &self->data_frame_parameters.destination_address,
	    destination_address_value);
}

void srp_encoding_listener_inc_first_value(struct srp_info_listener *self)
{
	uint64_t stream_id_value =
	    jdksavdecc_eui64_convert_to_uint64(&self->stream_id);
	stream_id_value++;
	jdksavdecc_eui64_init_from_uint64(&self->stream_id, stream_id_value);
}

void srp_encoding_domain_inc_first_value(struct srp_info_domain *self)
{
	self->class_id++;
	self->class_priority++;
}
