#ifndef _USER_STM32F10X_H
#define _USER_STM32F10X_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>


/*
*   GPIO Port modes bits definition provided by RM008.
*   00 : Input mode (reset state)   
*   01 : Output mode , max speed 10MHz
*   10 : Output mode , max speed 2MHz
*   11 : Output mode , max speed 50MHz
*/
enum { MODE_INPUT , MODE_OUT_2M , 
        MODE_OUT_10M , MODE_OUT_50M };



/*
*   GPIO Configuration bits definition provided by RM008.
*   In input mode (MODE[1:0] == 00)
*   00 : Analog mode 
*   01 : Floating input (reset state)
*   10 : Input with pull-up / pull-down
*   11 : Reserved
*/
enum { CNF_IN_ANAL , CNF_IN_FLOAT , 
        CNF_IN_PULL };



/*
*   GPIO Configuration bits definition provided by RM008.
*   In output mode (MODE[1:0] > 00)
*   00 : General purpose output push-pull
*   01 : General purpose output Open-drain
*   10 : Alternate function output Push-pull
*   11 : Alternate function output Open-drain
*/
enum { CNF_OUT_GP_PUSH , CNF_OUT_GP_OPEN , 
        CNF_OUT_AF_PUSH , CNF_OUT_AF_OPEN };


/*
*   SysTick Timer Control bits definition , provided by PM0056.
*   Counter Enable Bit 
*   0 : Counter Disabled
*   1 : Counter Enabled 
*/
enum {SYST_DISA , SYST_ENA };

/*
*   SysTick Timer Control bits definition , provided by PM0056.
*   SysTick Exception Request Enable bit
*   0 : Count down to zero do not assert the SysTick exception request ( trigger interrupt )
*   1 : Count down to zero assert the SysTick exception request
*/
enum {SYST_NOTRI , SYST_TRI };

/*
*   SysTick Timer Control bits definition , provided by PM0056.
*   SysTick Clock source selection 
*   0 : AHB/8
*   1 : Processor clock (AHB)
*/
enum {SYST_AHBD8 , SYST_AHB };


/*  Programming Interfaces */

//******** GPIO interfaces

//	port : PORT_A PORT_B PORT_C PORT_D PORT_E PORT_F 
//  mode : MODE_INPUT MODE_OUT_2M MODE_OUT_10M MODE_OUT_50M 
//  cnf  : When at MODE_INPUT , use 
//        CNF_IN_ANAL , CNF_IN_FLOAT , CNF_IN_PULL 
//         Otherwsie , use   
//        CNF_OUT_GP_PUSH , CNF_OUT_GP_OPEN , 
//        CNF_OUT_AF_PUSH , CNF_OUT_AF_OPEN    

//  posi : port position from 0 - 15 */
void GPIO_MODE_SET( GPIO_TypeDef* GPIO_cur , uint32_t mode , uint32_t cnf , uint32_t posi );

/* Set Coorsponding Port position bit */
void GPIO_BIT_SET(GPIO_TypeDef* GPIO_cur , uint32_t posi);

/* Reset Coorsponding Port position bit */
void GPIO_BIT_RESET(GPIO_TypeDef* GPIO_cur , uint32_t posi);

/* Read Coorsponding Port position bit */
bool GPIO_BIT_READ(GPIO_TypeDef* GPIO_cur , uint32_t posi);

/* Write 16 bit unsigned data to Specified GPIO port */
void GPIO_WRITE_DAT(GPIO_TypeDef* GPIO_cur, uint16_t dat);

/* Read data from Specofied GPIO port , 16 bit wide */
uint16_t GPIO_READ_DAT(GPIO_TypeDef* GPIO_cur);




//******** SysTick Interfaces

// Set SysTick control register , Clock Source , Exception Request , Counter Enable bits 
// All bits previouly set will be cleared 
void SysTick_MODE_SET(bool clkSource , bool tickInt , bool ena);        

        //These will clear nothing .
        void SysTick_CLKSRC_SET(bool clkSource);
        void SysTick_TIKINT_SET(bool tickInt);
        void SysTick_ENA_SET(bool ena);


// Read Status bit from SysTick control and status register  
// Returns 1 if timer counted to 0 since last time this was read. 
bool SysTick_STAB_READ(void);

// Set value for SysTick reload value register  
void SysTick_SET_VAL(uint32_t dat);

// Read current value of the SysTick from SysTick Current value register 
uint32_t SysTick_GET_VAL(void);

/*** Precise ms delay function implementation ***/

static volatile unsigned decrementCounter;	// SysTick In-program Counter.

static inline void _counterDecrement(){		// Decrement In-program Counter until 0.
	
	if( decrementCounter != 0 )
		--decrementCounter;
}



static inline void SysTick_Init(){		// Initialize SysTick to every 1ms interrupt mode.

	SysTick_MODE_SET(SYST_AHB , SYST_TRI , SYST_DISA);
	SysTick_SET_VAL(7200); // When clock at 72Mhz , this takes 1ms to operate.
	SysTick_ENA_SET(SYST_ENA);
}

inline void Delay_ms(uint32_t ms){		// Delay function in the unit of milliseconds.

	decrementCounter = ms;
	while( decrementCounter!=0 );
}



#endif
