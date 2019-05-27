// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019, Ben Coughlan - All Rights Reserved
 * Author(s): Ben Coughlan, <ben.coughlan@cgsy.com.au>.
 */
#include <common.h>
#include <envm.h>
#include <clock.h>

DECLARE_GLOBAL_DATA_PTR;

#ifdef CONFIG_DISPLAY_CPUINFO
int print_cpuinfo(void)
{
	printf("CPU: SmartFusion2 SoC");
	return 0;
}
#endif

/*
 * CPU specific initilization
 */
int arch_cpu_init(void)
{
	/*
	 * Initialize the eNVM driver
	 */
	envm_init();

	/*
	 * Initialize the timers.
	 */
	timer_init();

	/*
	 * Initialize the clock frequencies.
	 */
	clock_init();

	/*
	 * Address of the kernel boot parameters.
	 * Use start of the external RAM for that;
	 * kernel resides at offset 0x8000 in the external RAM.
	 */
	gd->bd->bi_boot_params = CONFIG_SYS_RAM_BASE;

        return 0;
}
