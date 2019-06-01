/*
 * (C) Copyright 2012
 *
 * Alexander Potashev, Emcraft Systems, aspotashev@emcraft.com
 * Vladimir Khusainov, Emcraft Systems, vlad@emcraft.com
 * Vladimir Skvortsov, Emcraft Systems, vskvortsov@emcraft.com
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#include <common.h>
#include <m2s.h>
#include <asm/armv7_mpu.h>

#ifdef CONFIG_M2S_CACHE_ON
/*
 * Enable the on-cache chip of SF2
 */
static void soc_cache_enable(void)
{

	M2S_SYSREG->cc_cr = 1 << 0;
}
#endif


int arch_cpu_init(void)
{
	/*
	 * Enable the on-chip cache
	 */
#ifdef CONFIG_M2S_CACHE_ON
	soc_cache_enable();
#endif

	/*
	 * Configure the memory protection unit (MPU) to allow full access to
	 * the whole 4GB address space.
	 *
	 * This is required, because in the default configuration code
	 * execution is not permitted at the addresses above 0xA0000000
	 * (including external DDR memory.)
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
