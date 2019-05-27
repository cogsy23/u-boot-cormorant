// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019, Ben Coughlan - All Rights Reserved
 * Author(s): Ben Coughlan, <ben.coughlan@cgsy.com.au>.
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#define CONFIG_ENV_SIZE         0x1000
#define CONFIG_SYS_LOAD_ADDR    0xA0000000

#define CONFIG_SYS_RAM_BASE     0xA0000000

#define CONFIG_SYS_MALLOC_LEN   0x3000

#define CONFIG_SYS_INIT_SP_ADDR 0x20050000

#define CONFIG_SYS_M2S_SYSREF   142000000
#define CONFIG_SYS_HZ_CLOCK     1000

#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_CLK		clock_get(CLOCK_PCLK0)
#define CONFIG_SYS_NS16550_COM1		0x40000000
#define CONFIG_BAUDRATE			115200

#endif /* __CONFIG_H */
