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

	auto pin = stm32::GPIO::Create(GPIOA, GPIO_PIN_5);
	pin->set(GPIO_PIN_SET);

	while (1) {
		pin->set(GPIO_PIN_SET);
		HAL_Delay(1000);
		printf("loop\n");
	}
	return 0;
}
