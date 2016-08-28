/*
 * stm32_gpio.h
 *
 *  Created on: 2016年8月28日
 *      Author: xec
 */

#ifndef STM32_GPIO_H_
#define STM32_GPIO_H_

namespace stm32 {

class GPIO {
public:
	GPIO(GPIO_TypeDef* type, uint32_t pin);

	virtual ~GPIO();

	void toggle();

private:
	GPIO_InitTypeDef pinDefine_;
	GPIO_TypeDef*    pinClass_;
};

} /* namespace stm32 */

#endif /* STM32_GPIO_H_ */
