// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019, Ben Coughlan - All Rights Reserved
 * Author(s): Ben Coughlan, <ben.coughlan@cgsy.com.au>.
 */
#include <common.h>

#ifdef CONFIG_DISPLAY_CPUINFO
int print_cpuinfo(void)
{
	printf("CPU: SmartFusion2 SoC");
	return 0;
}
#endif
