#include <stdint.h>
#include "gpio.h"



int main(void)
{
	/* Enable clock for GPIOA */
	ENABLE_GPIOA_Clock();

	/* Initialize GPIOA registers */
	GPIO_Init_TypeDef InitStruct = {0};
	InitStruct.Pin = GPIO_PIN_5; 	// LED is connected to PA5 --> GPIOA, Pin5
	InitStruct.Mode = GPIO_MODE_OUTPUT;

	GPIO_Init(GPIOA, &InitStruct);

    /* Loop forever */
	for(;;)
	{
		GPIO_Toggle_Pin(GPIOA, GPIO_PIN_5);
		for (int i = 0; i < 500000;++i);
	}
}
