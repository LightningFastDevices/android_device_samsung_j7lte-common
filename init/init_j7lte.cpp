/*
   Copyright (c) 2017, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
	* Redistributions of source code must retain the above copyright
	  notice, this list of conditions and the following disclaimer.
	* Redistributions in binary form must reproduce the above
	  copyright notice, this list of conditions and the following
	  disclaimer in the documentation and/or other materials provided
	  with the distribution.
	* Neither the name of The Linux Foundation nor the names of its
	  contributors may be used to endorse or promote products derived
	  from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <init_msm8916.h>

void init_target_properties(void)
{
	char *bootloader_str = NULL;
	char *build_id = NULL;
	char *device = NULL;
	char *model = NULL;
	char *name = NULL;
	char *operator_alpha = NULL;
	char *operator_numeric = NULL;
	char *version_release = NULL;

	int network_type = 1;

	/* get the bootloader string */
	std::string bootloader = property_get("ro.bootloader");

	if (bootloader.find("J700P") == 0) {
		build_id = (char *)"MMB29M";
		device = (char *)"j7ltespr";
		model = (char *)"SM-J700P";
		operator_alpha = (char *)"Chameleon";
		operator_numeric = (char *)"310000";
		network_type=CDMA_DEVICE;
		version_release = (char *)"6.0.1";
	}
	else if (bootloader.find("J7008") == 0) {
		build_id = (char *)"LMY47O";
		device = (char *)"j7ltechn";
		model = (char *)"SM-J7008";
		name = (char *)"j7ltezm";
		network_type=LTE_DEVICE;
		version_release = (char *)"5.1";
	}
	else {
		return;
	}

	/* make sure device name is set */
	if (name == NULL)
		name = device;

	/* set the properties */
	set_target_properties(build_id, bootloader_str, name, device, model,
		       network_type, operator_alpha, operator_numeric, version_release);
}
