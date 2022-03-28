#include <stdint.h>

#include "stm32f10x.h"

#include "stm32f10x_it.h"
#include "stm32f10x_gpio.h"

GPIO_InitTypeDef* PC13_LED;

void LED_TOGGLE(){
	
	if(GPIO_ReadOutputDataBit(GPIOC , 13))
		GPIO_ResetBits(GPIOC , 13);
		
	else
		GPIO_SetBits(GPIOC , 13);


}


static __IO uint32_t TimingDelay;

void Delay(__IO uint32_t nTime);

int main(){

	PC13_LED->GPIO_Pin = 13; 
	PC13_LED->GPIO_Speed = GPIO_Speed_2MHz;
	PC13_LED->GPIO_Mode = GPIO_Mode_Out_OD;

	GPIO_Init(GPIOC , PC13_LED);

	while(1){

	LED_TOGGLE();

	}

	return 0;
}


/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in milliseconds.
  * @retval None
  */
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

