// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019, Ben Coughlan - All Rights Reserved
 * Author(s): Ben Coughlan, <ben.coughlan@cgsy.com.au>.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_SYS_LOAD_ADDR    0xA0000000

#define CONFIG_SYS_SDRAM_BASE   0xA0000000

#define CONFIG_SYS_MALLOC_LEN   0x3000
#define CONFIG_ENV_SIZE         0x1000

#define CONFIG_SYS_INIT_SP_ADDR 0x20010000

#define CONFIG_SYS_M2S_SYSREF   100000000
#define CONFIG_SYS_HZ_CLOCK     1000

#define CONFIG_BLUE_LED         3
#define CONFIG_YELLOW_LED       2
#define CONFIG_RED_LED          1
#define CONFIG_GREEN_LED        0

#endif /* __CONFIG_H */
