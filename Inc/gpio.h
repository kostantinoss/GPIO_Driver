#include <stdint.h>


#define PERIPH_BASE         0x40000000UL
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE            (AHB1PERIPH_BASE + 0x3800UL)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)

#define GPIOA_BASE 			(AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE          (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE          (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE          (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE          (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOH_BASE          (AHB1PERIPH_BASE + 0x1C00UL)

#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOH               ((GPIO_TypeDef *) GPIOH_BASE)

#define GPIOA_ENABLE 	(1UL << 0);


typedef struct {
	uint32_t allign[12];
	volatile uint32_t AHB1ENR;
} RCC_TypeDef;


typedef enum {
    GPIO_PIN_0 = 0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,
    GPIO_PIN_8,
    GPIO_PIN_9,
    GPIO_PIN_10,
    GPIO_PIN_11,
    GPIO_PIN_12,
    GPIO_PIN_13,
    GPIO_PIN_14,
    GPIO_PIN_15
} GPIO_Pin_t;


typedef enum {
    GPIO_MODE_INPUT = 0UL,
    GPIO_MODE_OUTPUT = 1UL,
    GPIO_MODE_ALTFUNC = 2UL,
    GPIO_MODE_ANALOG = 3UL
} GPIO_Mode_t;


typedef struct {
	uint32_t Pin;
	uint32_t Mode;
	uint32_t Speed;
	uint32_t OutputType;
	uint32_t Pull;
	uint32_t Alternate;
} GPIO_Init_TypeDef;


typedef struct
{
  volatile uint32_t MODER;
  volatile uint32_t OTYPER;
  volatile uint32_t OSPEEDR;
  volatile uint32_t PUPDR;
  volatile uint32_t IDR;
  volatile uint32_t ODR;
  volatile uint32_t BSRR;
  volatile uint32_t LCKR;
  volatile uint32_t AFR[2];
} GPIO_TypeDef;


void ENABLE_GPIOA_Clock();

int GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_Init_TypeDef *InitStruct);
int GPIO_Set_Pin_Mode(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode);
int GPIO_Toggle_Pin(GPIO_TypeDef *GPIOx, uint32_t Pin) ;



