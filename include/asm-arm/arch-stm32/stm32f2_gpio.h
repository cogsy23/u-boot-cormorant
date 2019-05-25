/*
 * (C) Copyright 2011
 *
 * Yuri Tikhonov, Emcraft Systems, yur@emcraft.com
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

#ifndef _STM32F2_GPIO_H_
#define _STM32F2_GPIO_H_

/*
 * GPIO roles (alternative functions); role determines by whom GPIO is used
 */
enum stm32f2_gpio_role {
	STM32F2_GPIO_ROLE_USART1,	/* USART1			      */
	STM32F2_GPIO_ROLE_USART2,	/* USART2			      */
	STM32F2_GPIO_ROLE_USART3,	/* USART3			      */
	STM32F2_GPIO_ROLE_USART4,	/* USART4			      */
	STM32F2_GPIO_ROLE_USART5,	/* USART5			      */
	STM32F2_GPIO_ROLE_USART6,	/* USART6			      */
	STM32F2_GPIO_ROLE_ETHERNET,	/* MAC				      */
	STM32F2_GPIO_ROLE_MCO,		/* MC external output clock	      */
	STM32F2_GPIO_ROLE_FSMC		/* FSMC static memory controller      */
};

/*
 * GPIO descriptor
 */
struct stm32f2_gpio_dsc {
	u32		port;		/* GPIO port			      */
	u32		pin;		/* GPIO pin			      */
};

/*
 * Configure the specified GPIO for the specified role
 */
int stm32f2_gpio_config(struct stm32f2_gpio_dsc *gpio_dsc,
			enum stm32f2_gpio_role role);

#endif /* _STM32F2_GPIO_H_ */
