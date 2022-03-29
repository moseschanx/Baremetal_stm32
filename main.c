#include <stdint.h>

#include "stm32f10x.h"

#include "stm32f10x_it.h"
#include "stm32f10x_gpio.h"

GPIO_InitTypeDef LED;


uint32_t global_var = 0xFF;

void Delay(__IO uint32_t nTime);

int main(){

	uint32_t *APB2_CLK_ENA =(uint32_t*) 0x40021018; 
	*APB2_CLK_ENA |=(uint32_t) (1<<4);

	uint32_t *GPIOC_CRH =(uint32_t*) 0x40011004; 
	*GPIOC_CRH |= (uint32_t)(1<<20);
	*GPIOC_CRH |=(uint32_t) (0<<22);


	uint32_t *GPIOC_ODR =(uint32_t*) 0x400110C;
	*GPIOC_ODR &=(uint32_t) (1<<13);

	while(1);

}


/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
static __IO uint32_t TimingDelay;

void Delay(__IO uint32_t nTime)
{ 
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}

