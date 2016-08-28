/*
 * stm32_gpio.cpp
 *
 *  Created on: 2016年8月28日
 *      Author: xec
 */
#include <stm32f4xx_hal.h>
#include "stm32_gpio.h"

namespace stm32 {

GPIO::GPIO(GPIO_TypeDef* type, uint32_t pin) {
	pinDefine_.Pin = pin;
	pinDefine_.Mode = GPIO_MODE_OUTPUT_PP;
	pinDefine_.Pull = GPIO_NOPULL;
	pinDefine_.Speed = GPIO_SPEED_HIGH;

	pinClass_ = type;

	HAL_GPIO_Init(type, &pinDefine_);
}

GPIO::~GPIO() {
	// TODO Auto-generated destructor stub
}


void GPIO::toggle() {
	HAL_GPIO_TogglePin(pinClass_, pinDefine_.Pin);
}

} /* namespace stm32 */
