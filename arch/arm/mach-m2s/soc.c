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
	/*
	 * Enable cache
	 */
	M2S_SYSREG->cc_cr = 1 << 0;
}
#endif

/*
 * SoC configuration code that cannot be put into drivers
 */
#if defined(CONFIG_ARCH_MISC_INIT)
int arch_misc_init(void)
{

#ifdef CONFIG_M2S_CACHE_ON

	/*
	 * Enable the on-chip cache
	 */
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
		.xn = XN_EN,
		.ap = PRIV_RW_USR_RW,
		.mr_attr = STRONG_ORDER,
		.reg_size = REGION_4GB
	};
	mpu_config(&cfg);
}
#endif /* CONFIG_ARCH_MISC_INIT */
