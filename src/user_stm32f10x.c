#include "stm32f10x.h"
#include "user_stm32f10x.h"



//******** GPIO Interfaces
void GPIO_MODE_SET( GPIO_TypeDef* GPIO_cur , uint32_t mode , uint32_t cnf , uint32_t posi ){


    uint32_t GPIO_CRL_MODE_cur_0,
             GPIO_CRL_MODE_cur_1,
             GPIO_CRL_CNF_cur_0,
             GPIO_CRL_CNF_cur_1;

    uint32_t GPIO_CRH_MODE_cur_0,
             GPIO_CRH_MODE_cur_1,
             GPIO_CRH_CNF_cur_0,
             GPIO_CRH_CNF_cur_1;

        GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE_cur_1 = GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF_cur_1 
        = GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE_cur_1 = GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF_cur_1 = NULL;

	/* Open Port Clock */	
    if(GPIO_cur == GPIOA)
			RCC->APB2ENR |= (uint32_t)(RCC_APB2ENR_IOPAEN);
    else if(GPIO_cur == GPIOB)
			RCC->APB2ENR |= (uint32_t)(RCC_APB2ENR_IOPBEN);
	else if(GPIO_cur == GPIOC)
			RCC->APB2ENR |= (uint32_t)(RCC_APB2ENR_IOPCEN);
    else if(GPIO_cur == GPIOD)
			RCC->APB2ENR |= (uint32_t)(RCC_APB2ENR_IOPDEN);
    else if(GPIO_cur == GPIOE)
           // RCC->APB2ENR |= (uint32_t)(RCC_APB2ENR_IOPEEN);

    /* Select port position and set mode,configuration bits*/ 
    switch(posi){
        case 0:  
            GPIO_cur -> CRL &= ~(uint32_t)(GPIO_CRL_MODE0 | GPIO_CRL_CNF0);
            GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE0_0;
            GPIO_CRL_MODE_cur_1 = GPIO_CRL_MODE0_1;
            GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF0_0;
            GPIO_CRL_CNF_cur_1 = GPIO_CRL_CNF0_1;
        break;
        case 1:
            GPIO_cur -> CRL &= ~(uint32_t)(GPIO_CRL_MODE1 | GPIO_CRL_CNF1);
            GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE1_0;
            GPIO_CRL_MODE_cur_1 = GPIO_CRL_MODE1_1;
            GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF1_0;
            GPIO_CRL_CNF_cur_1 = GPIO_CRL_CNF1_1;

        break;
        case 2:
            GPIO_cur -> CRL &= ~(uint32_t)(GPIO_CRL_MODE2 | GPIO_CRL_CNF2);
            GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE2_0;
            GPIO_CRL_MODE_cur_1 = GPIO_CRL_MODE2_1;
            GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF2_0;
            GPIO_CRL_CNF_cur_1 = GPIO_CRL_CNF2_1;
            

        break;
        case 3:
            GPIO_cur -> CRL &= ~(uint32_t)(GPIO_CRL_MODE3 | GPIO_CRL_CNF3);
            GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE3_0;
            GPIO_CRL_MODE_cur_1 = GPIO_CRL_MODE3_1;
            GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF3_0;
            GPIO_CRL_CNF_cur_1 = GPIO_CRL_CNF3_1;
        break;
        case 4:
            GPIO_cur -> CRL &= ~(uint32_t)(GPIO_CRL_MODE4 | GPIO_CRL_CNF4);
            GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE4_0;
            GPIO_CRL_MODE_cur_1 = GPIO_CRL_MODE4_1;
            GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF4_0;
            GPIO_CRL_CNF_cur_1 = GPIO_CRL_CNF4_1;

        break;
        case 5:
            GPIO_cur -> CRL &= ~(uint32_t)(GPIO_CRL_MODE5 | GPIO_CRL_CNF5);
            GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE5_0;
            GPIO_CRL_MODE_cur_1 = GPIO_CRL_MODE5_1;
            GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF5_0;
            GPIO_CRL_CNF_cur_1 = GPIO_CRL_CNF5_1;

        break;
        case 6:
            GPIO_cur -> CRL &= ~(uint32_t)(GPIO_CRL_MODE6 | GPIO_CRL_CNF6);
            GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE6_0;
            GPIO_CRL_MODE_cur_1 = GPIO_CRL_MODE6_1;
            GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF6_0;
            GPIO_CRL_CNF_cur_1 = GPIO_CRL_CNF6_1;

        break;
        case 7:
            GPIO_cur -> CRL &= ~(uint32_t)(GPIO_CRL_MODE7 | GPIO_CRL_CNF7);
            GPIO_CRL_MODE_cur_0 = GPIO_CRL_MODE7_0;
            GPIO_CRL_MODE_cur_1 = GPIO_CRL_MODE7_1;
            GPIO_CRL_CNF_cur_0 = GPIO_CRL_CNF7_0;
            GPIO_CRL_CNF_cur_1 = GPIO_CRL_CNF7_1;

        break;
        case 8:
            GPIO_cur -> CRH &= ~(uint32_t)(GPIO_CRH_MODE8 | GPIO_CRH_CNF8);
            GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE8_0;
            GPIO_CRH_MODE_cur_1 = GPIO_CRH_MODE8_1;
            GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF8_0;
            GPIO_CRH_CNF_cur_1 = GPIO_CRH_CNF8_1;

        break;
        case 9:
            GPIO_cur -> CRH &= ~(uint32_t)(GPIO_CRH_MODE9 | GPIO_CRH_CNF9);
            GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE9_0;
            GPIO_CRH_MODE_cur_1 = GPIO_CRH_MODE9_1;
            GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF9_0;
            GPIO_CRH_CNF_cur_1 = GPIO_CRH_CNF9_1;

        break;
        case 10:
            GPIO_cur -> CRH &= ~(uint32_t)(GPIO_CRH_MODE10 | GPIO_CRH_CNF10);
            GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE10_0;
            GPIO_CRH_MODE_cur_1 = GPIO_CRH_MODE10_1;
            GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF10_0;
            GPIO_CRH_CNF_cur_1 = GPIO_CRH_CNF10_1;

        break;
        case 11:
            GPIO_cur -> CRH &= ~(uint32_t)(GPIO_CRH_MODE11 | GPIO_CRH_CNF11);
            GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE11_0;
            GPIO_CRH_MODE_cur_1 = GPIO_CRH_MODE11_1;
            GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF11_0;
            GPIO_CRH_CNF_cur_1 = GPIO_CRH_CNF11_1;

        break;
        case 12:
            GPIO_cur -> CRH &= ~(uint32_t)(GPIO_CRH_MODE12 | GPIO_CRH_CNF12);
            GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE12_0;
            GPIO_CRH_MODE_cur_1 = GPIO_CRH_MODE12_1;
            GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF12_0;
            GPIO_CRH_CNF_cur_1 = GPIO_CRH_CNF12_1;

        break;
        case 13:
            GPIO_cur -> CRH &= ~(uint32_t)(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
            GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE13_0;
            GPIO_CRH_MODE_cur_1 = GPIO_CRH_MODE13_1;
            GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF13_0;
            GPIO_CRH_CNF_cur_1 = GPIO_CRH_CNF13_1;

        break;
        case 14:
            GPIO_cur -> CRH &= ~(uint32_t)(GPIO_CRH_MODE14 | GPIO_CRH_CNF14);
            GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE14_0;
            GPIO_CRH_MODE_cur_1 = GPIO_CRH_MODE14_1;
            GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF14_0;
            GPIO_CRH_CNF_cur_1 = GPIO_CRH_CNF14_1;

        break;
        case 15:
            GPIO_cur -> CRH &= ~(uint32_t)(GPIO_CRH_MODE15 | GPIO_CRH_CNF15);
            GPIO_CRH_MODE_cur_0 = GPIO_CRH_MODE15_0;
            GPIO_CRH_MODE_cur_1 = GPIO_CRH_MODE15_1;
            GPIO_CRH_CNF_cur_0 = GPIO_CRH_CNF15_0;
            GPIO_CRH_CNF_cur_1 = GPIO_CRH_CNF15_1;

        break;
    }
    
    if(posi<8){

            switch(mode){
                case 00:
                    break;
                case 01:
                    GPIO_cur -> CRL |= (uint32_t)(GPIO_CRL_MODE_cur_0);
                    break;
                case 02:
                    GPIO_cur -> CRL |= (uint32_t)(GPIO_CRL_MODE_cur_1);
                    break;
                case 03:
                    GPIO_cur -> CRL |= (uint32_t)(GPIO_CRL_MODE_cur_1 | GPIO_CRL_MODE_cur_0);
                    break;
            }
            switch(cnf){
                case 00:
                    break;
                case 01:
                    GPIO_cur -> CRL |= (uint32_t)(GPIO_CRL_CNF_cur_0);
                    break;
                case 02:
                    GPIO_cur -> CRL |= (uint32_t)(GPIO_CRL_CNF_cur_1);
                    break;
                case 03:
                    GPIO_cur -> CRL |= (uint32_t)(GPIO_CRL_CNF_cur_0 | GPIO_CRL_CNF_cur_1);
                    break;
            }


    }
    else{

            switch(mode){
                case 00:
                    break;
                case 01:
                    GPIO_cur -> CRH |= (uint32_t)(GPIO_CRH_MODE_cur_0);
                    break;
                case 02:
                    GPIO_cur -> CRH |= (uint32_t)(GPIO_CRH_MODE_cur_1);
                    break;
                case 03:
                    GPIO_cur -> CRH |= (uint32_t)(GPIO_CRH_MODE_cur_1 | GPIO_CRH_MODE_cur_0);
                    break;
            }
            switch(cnf){
                case 00:
                    break;
                case 01:
                    GPIO_cur -> CRH |= (uint32_t)(GPIO_CRH_CNF_cur_0);
                    break;
                case 02:
                    GPIO_cur -> CRH |= (uint32_t)(GPIO_CRH_CNF_cur_1);
                    break;
                case 03:
                    GPIO_cur -> CRH |= (uint32_t)(GPIO_CRH_CNF_cur_0 | GPIO_CRH_CNF_cur_1);
                    break;
            }


    } 

}

void GPIO_BIT_RESET(GPIO_TypeDef* GPIO_cur , uint32_t posi){

   switch(posi){
        case 0:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR0;	//Close Bit
            break;
        case 1:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR1;
            break;
        case 2:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR2;
            break;
        case 3:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR3;
            break;
        case 4:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR4;
            break;
        case 5:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR5;
            break;
        case 6:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR6;
            break;
        case 7:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR7;
            break;
        case 8:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR8;
            break;
        case 9:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR9;
            break;
        case 10:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR10;
            break;
        case 11:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR11;
            break;
        case 12:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR12;
            break;
        case 13:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR13;
            break;
        case 14:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR14;
            break;
        case 15:
            GPIO_cur -> ODR &= ~(uint32_t)GPIO_ODR_ODR15;
            break;
        default :
            break;
        }

}

void GPIO_BIT_SET(GPIO_TypeDef* GPIO_cur , uint32_t posi){

   switch(posi){
        case 0:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR0;	//Open Bit
            break;
        case 1:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR1;
            break;
        case 2:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR2;
            break;
        case 3:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR3;
            break;
        case 4:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR4;
            break;
        case 5:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR5;
            break;
        case 6:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR6;
            break;
        case 7:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR7;
            break;
        case 8:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR8;
            break;
        case 9:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR9;
            break;
        case 10:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR10;
            break;
        case 11:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR11;
            break;
        case 12:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR12;
            break;
        case 13:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR13;
            break;
        case 14:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR14;
            break;
        case 15:
            GPIO_cur -> ODR |= (uint32_t)GPIO_ODR_ODR15;
            break;
        default :
            break;
        }
}

bool GPIO_BIT_READ(GPIO_TypeDef* GPIO_cur , uint32_t posi){

   switch(posi){
        case 0:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR0);
        case 1:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR1);
        case 2:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR2);
        case 3:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR3);
        case 4:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR4);
        case 5:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR5);
        case 6:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR6);
        case 7:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR7);
        case 8:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR8);
        case 9:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR9);
        case 10:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR10);
        case 11:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR11);
        case 12:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR12);
        case 13:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR13);
        case 14:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR14);
        case 15:
            return (bool)(GPIO_cur -> IDR & GPIO_IDR_IDR15);
        default :
            return 0;
        }

}

void GPIO_WRITE_DAT(GPIO_TypeDef* GPIO_cur, uint16_t dat){

    GPIO_cur -> ODR = (uint32_t)dat;

}
uint16_t GPIO_READ_DAT(GPIO_TypeDef* GPIO_cur){

    return (uint16_t)(GPIO_cur -> IDR);

}


//******** SysTick Interfaces
inline void SysTick_MODE_SET(bool clkSource , bool tickInt , bool ena){

    // Close all bits in SysTick Control Register
    SysTick->CTRL &= ~(uint32_t)(SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk 
                                | SysTick_CTRL_ENABLE_Msk);


    if(clkSource){
        SysTick->CTRL |= (uint32_t)(SysTick_CTRL_CLKSOURCE_Msk);
    }
    else{
        SysTick->CTRL &= ~(uint32_t)(SysTick_CTRL_CLKSOURCE_Msk);
    }

    if(tickInt){
        SysTick->CTRL |= (uint32_t)(SysTick_CTRL_TICKINT_Msk);
    }
    else{
        SysTick->CTRL &= ~(uint32_t)(SysTick_CTRL_TICKINT_Msk);
    }

    if(ena){
        SysTick->CTRL |= (uint32_t)(SysTick_CTRL_ENABLE_Msk);
    }
    else{
        SysTick->CTRL &= ~(uint32_t)(SysTick_CTRL_ENABLE_Msk);
    }
    
    
}

inline void SysTick_CLKSRC_SET(bool clkSource){

    if(clkSource){
        SysTick->CTRL |= (uint32_t)(SysTick_CTRL_CLKSOURCE_Msk);
    }
    else{
        SysTick->CTRL &= ~(uint32_t)(SysTick_CTRL_CLKSOURCE_Msk);
    }

}

inline void SysTick_TIKINT_SET(bool tickInt){

    if(tickInt){
        SysTick->CTRL |= (uint32_t)(SysTick_CTRL_TICKINT_Msk);
    }
    else{
        SysTick->CTRL &= ~(uint32_t)(SysTick_CTRL_TICKINT_Msk);
    }

}

inline void SysTick_ENA_SET(bool ena){

    if(ena){
        SysTick->CTRL |= (uint32_t)(SysTick_CTRL_ENABLE_Msk);
    }
    else{
        SysTick->CTRL &= ~(uint32_t)(SysTick_CTRL_ENABLE_Msk);
    }

}

inline bool SysTick_STAB_READ(){

    return (bool)(SysTick-> CTRL & SysTick_CTRL_COUNTFLAG_Msk);



}


inline void SysTick_SET_VAL(uint32_t dat){

    SysTick -> LOAD = dat;

}

 uint32_t SysTick_GET_VAL(){

    return (uint32_t)(SysTick -> VAL);
}
