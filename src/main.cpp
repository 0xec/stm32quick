//
// This file is part of the GNU ARM Eclipse distribution.
// Copyright (c) 2014 Liviu Ionescu.
//

// ----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <memory>
#include <stm32f4xx.h>
#include "diag/Trace.h"
#include "hardware.h"
#include "stm32_gpio.h"

int main() {
	__initialize_hardware();

	std::shared_ptr<stm32::GPIO> ptr = std::make_shared<stm32::GPIO>(GPIOA, GPIO_PIN_5);


	while (1) {
		ptr->toggle();
		HAL_Delay(1000);
		printf("loop\n");
	}
	return 0;
}
