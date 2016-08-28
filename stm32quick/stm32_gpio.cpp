/*
 * stm32_gpio.cpp
 *
 *  Created on: 2016年8月28日
 *      Author: xec
 */
#include <memory>
#include <stm32f4xx_hal.h>
#include "stm32_gpio.h"

namespace stm32 {

GPIO::GPIO(GPIO_TypeDef* type, uint32_t pin) {

	__HAL_RCC_GPIOA_CLK_ENABLE()
	;

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

std::shared_ptr<GPIO> GPIO::Create(GPIO_TypeDef* type, uint32_t pin) {
	return std::make_shared<GPIO>(type, pin);
}

void GPIO::toggle() {
	HAL_GPIO_TogglePin(pinClass_, pinDefine_.Pin);

}

void GPIO::set(GPIO_PinState state) {
	state_ = state;
	HAL_GPIO_WritePin(pinClass_, pinDefine_.Pin, state);
}

} /* namespace stm32 */
