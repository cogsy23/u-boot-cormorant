// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019, Ben Coughlan - All Rights Reserved
 * Author(s): Ben Coughlan, <ben.coughlan@cgsy.com.au>.
 */
#include <common.h>
#include <m2s.h>
#include <asm/armv7_mpu.h>

int arch_cpu_init(void)
{
	/*
	 * Enable the on-chip cache
	 */
	#ifndef CONFIG_SYS_ICACHE_OFF
	M2S_SYSREG->cc_cr = 1 << 0;
	#endif

	/*
	 * Open the MPU for everything
	 */
	struct mpu_region_config cfg = {
		.start_addr = 0x00000000,
		.region_no = REGION_0,
		.xn = XN_DIS,
		.ap = PRIV_RW_USR_RW,
		.mr_attr = O_I_WB_RD_WR_ALLOC,
		.reg_size = REGION_4GB
	};

	disable_mpu();
	mpu_config(&cfg);
	enable_mpu();

	return 0;
}
