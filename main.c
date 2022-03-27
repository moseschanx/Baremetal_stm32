#include <stdint.h>
#include "stm32f10x.h"

uint32_t global_counter = 4;

int main(){


while(1){
	while(global_counter==0){
		if(global_counter==0xFFFFFFFF)
			global_counter=0;
	global_counter++;
}

	return 0;
}

}
