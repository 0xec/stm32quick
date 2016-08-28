#include <stm32f4xx.h>

void HAL_IncTick(void);

void SysTick_Handler(void) {
	HAL_IncTick();
}
