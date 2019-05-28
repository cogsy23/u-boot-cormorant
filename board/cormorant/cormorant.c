// SPDX-License-Identifier: GPL-2.0+
/*
 * Copyright (C) 2019, Ben Coughlan - All Rights Reserved
 * Author(s): Ben Coughlan, <ben.coughlan@cgsy.com.au>.
 */

#include <common.h>

DECLARE_GLOBAL_DATA_PTR;

int dram_init(void)
{
	return 0;
}

int board_init(void)
{
	blue_led_on();
	return 0;
}

int board_early_init_f(void)
{
	green_led_on();
	return 0;

}

int board_early_init_r(void)
{
	red_led_on();
	return 0;
}

static uint32_t volatile * const GPIO_CFG = (uint32_t *)0x40013000;
static uint32_t volatile * const GPIO_OUT = (uint32_t *)0x40013088;

void gpio_set(gpio, val)
{
	*GPIO_OUT = (*GPIO_OUT & ~(1 << gpio)) | (val << gpio);
}

void coloured_LED_init(void)
{
	GPIO_CFG[0] = 0x05;
	GPIO_CFG[1] = 0x05;
	GPIO_CFG[2] = 0x05;
	GPIO_CFG[3] = 0x05;
}

void red_led_off(void)
{
	gpio_set(CONFIG_RED_LED, 0);
}

void green_led_off(void)
{
	gpio_set(CONFIG_GREEN_LED, 0);
}

void yellow_led_off(void)
{
	gpio_set(CONFIG_YELLOW_LED, 0);
}

void blue_led_off(void)
{
	gpio_set(CONFIG_BLUE_LED, 0);
}

void red_led_on(void)
{
	gpio_set(CONFIG_RED_LED, 1);
}

void green_led_on(void)
{
	gpio_set(CONFIG_GREEN_LED, 1);
}

void yellow_led_on(void)
{
	gpio_set(CONFIG_YELLOW_LED, 1);
}

void blue_led_on(void)
{
	gpio_set(CONFIG_BLUE_LED, 1);
}
