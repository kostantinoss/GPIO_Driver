# Simple GPIO Driver
This is a very simple GPIO driver for STM32F401RE.

My goal is to get familiar with the architecture of the board, thats why I opted to not to use HAL or LL drivers that ST Microelectrinics provide.\
The header file structure and API is heavily influenced bu LL drivers but I'v defined only the peripherals that concern GPIO.

### Brief API Documentation
- __int GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_Init_TypeDef *InitStruct)__:\
  Initializes GPIO registers usind the InitStruct
- __int GPIO_Set_Pin_Mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)__:\
  Configures mode for given pin
- __int GPIO_Toggle_Pin(GPIO_TypeDef *GPIOx, uint32_t Pin)__:\
  Toggle given pin value.
    
### Example
A LED toggle example is implemented in main.c
```
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
  for(;;) {
    GPIO_Toggle_Pin(GPIOA, GPIO_PIN_5);

    // wait some time...
    for (int i = 0; i < 500000;++i);
  }
}
```

I'm using STM32CubeIDE for development.

## TODO:
- [ ] Write wait functions usinf SysTick timer.
- [ ] Refine API and make it more generic
