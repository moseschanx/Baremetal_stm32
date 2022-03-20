#include <stdint.h>
#include "stm32f10x.h"
#include "user_stm32f10x.h"

uint32_t global_counter = 4;

int main(){

	GPIO_MODE_SET(GPIOC,MODE_OUT_10M,CNF_OUT_GP_PUSH,13);
	GPIO_BIT_RESET(GPIOC,13);

while(1){
	while(global_counter==0)
		if(global_counter==0xFFFFFFFF)
			global_counter=0;
	global_counter++;
}

	return 0;
}
