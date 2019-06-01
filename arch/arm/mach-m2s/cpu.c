// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019, Ben Coughlan - All Rights Reserved
 * Author(s): Ben Coughlan, <ben.coughlan@cgsy.com.au>.
 */
#include <common.h>

DECLARE_GLOBAL_DATA_PTR;

int print_cpuinfo(void)
{
	printf("CPU: SmartFusion2 SoC\n");
	return 0;
}
