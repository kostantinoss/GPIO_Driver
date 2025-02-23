#include <stdlib.h>
#include "gpio.h"


void ENABLE_GPIOA_Clock() {
	RCC->AHB1ENR |= GPIOA_ENABLE;
}


int GPIO_Set_Pin_Mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode) {
	// Clear Pin bits, then set mode.
	GPIOx->MODER &= ~(3UL << (2 * Pin));
	GPIOx->MODER |= (Mode << (2 * Pin));
	return 0;
}

int GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_Init_TypeDef *InitStruct) {
	// TODO: Add more setter functions for all other registers.
	GPIO_Set_Pin_Mode(GPIOx, InitStruct->Pin, InitStruct->Mode);
	GPIO_Set_Pin_Af(GPIOx, InitStruct->Pin, InitStruct->Af);

	return 0;
}

int GPIO_Toggle_Pin(GPIO_TypeDef *GPIOx, uint32_t Pin) {
	GPIOx->ODR ^= (1UL << Pin);
	return 0;
}
