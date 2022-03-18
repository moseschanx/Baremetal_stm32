#include <stdint.h>

#define SRAM_START	 0x20000000U
#define SRAM_SIZE 	 (20U * 1024U)
#define SRAM_END  	 (SRAM_START + SRAM_SIZE)
#define STACK_START	 SRAM_START + 0x400U

extern int main(void);
extern void SystemInit (void);

extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _stext;
extern uint32_t _etext;
extern uint32_t _sbss;
extern uint32_t _ebss;

// Vector table for other STM32F10xxx devices
void Reset_handler(void);

void NMI_handler(void)__attribute__((weak,alias("Default_handler")));
void HardFault_handler(void)__attribute__((weak,alias("Default_handler")));
void MemManage_handler(void)__attribute__((weak,alias("Default_handler")));
void BusFault_handler(void)__attribute__((weak,alias("Default_handler")));
void UsageFault_handler(void)__attribute__((weak,alias("Default_handler")));
void SVCall_handler(void)__attribute__((weak,alias("Default_handler")));
void DebugMonitor_handler(void)__attribute__((weak,alias("Default_handler")));
void PendSV_handler(void)__attribute__((weak,alias("Default_handler")));
void SysTick_handler(void)__attribute__((weak,alias("Default_handler")));
void WWDG_handler(void)__attribute__((weak,alias("Default_handler")));
void PVD_handler(void)__attribute__((weak,alias("Default_handler")));
void TAMPER_handler(void)__attribute__((weak,alias("Default_handler")));
void RTC_handler(void)__attribute__((weak,alias("Default_handler")));
void FLASH_handler(void)__attribute__((weak,alias("Default_handler")));
void RCC_handler(void)__attribute__((weak,alias("Default_handler")));
void EXTI0_handler(void)__attribute__((weak,alias("Default_handler")));
void EXTI1_handler(void)__attribute__((weak,alias("Default_handler")));
void EXTI2_handler(void)__attribute__((weak,alias("Default_handler")));
void EXTI3_handler(void)__attribute__((weak,alias("Default_handler")));
void EXTI4_handler(void)__attribute__((weak,alias("Default_handler")));
void DMI_Channel1_handler(void)__attribute__((weak,alias("Default_handler")));
void DMI_Channel2_handler(void)__attribute__((weak,alias("Default_handler")));
void DMI_Channel3_handler(void)__attribute__((weak,alias("Default_handler")));
void DMI_Channel4_handler(void)__attribute__((weak,alias("Default_handler")));
void DMI_Channel5_handler(void)__attribute__((weak,alias("Default_handler")));
void DMI_Channel6_handler(void)__attribute__((weak,alias("Default_handler")));
void DMI_Channel7_handler(void)__attribute__((weak,alias("Default_handler")));
void ADC1_2_handler(void)__attribute__((weak,alias("Default_handler")));
void USB_HP_CAN_TX_handler(void)__attribute__((weak,alias("Default_handler")));
void USB_LP_CAN_RX0_handler(void)__attribute__((weak,alias("Default_handler")));
void CAN_RX1_handler(void)__attribute__((weak,alias("Default_handler")));
void CAN_SCE_handler(void)__attribute__((weak,alias("Default_handler")));
void EXTI9_5_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM1_BRK(void)__attribute__((weak,alias("Default_handler")));
void TIM1_UP_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM1_TRG_COM_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM1_CC_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM2_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM3_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM4_handler(void)__attribute__((weak,alias("Default_handler")));
void I2C1_EV_handler(void)__attribute__((weak,alias("Default_handler")));
void I2C1_ER_handler(void)__attribute__((weak,alias("Default_handler")));
void I2C2_EV_handler(void)__attribute__((weak,alias("Default_handler")));
void I2C2_ER_handler(void)__attribute__((weak,alias("Default_handler")));
void SPI1_handler(void)__attribute__((weak,alias("Default_handler")));
void SPI2_handler(void)__attribute__((weak,alias("Default_handler")));
void USART1_handler(void)__attribute__((weak,alias("Default_handler")));
void USART2_handler(void)__attribute__((weak,alias("Default_handler")));
void USART3_handler(void)__attribute__((weak,alias("Default_handler")));
void EXTI15_10_handler(void)__attribute__((weak,alias("Default_handler")));
void RTCAlarm_handler(void)__attribute__((weak,alias("Default_handler")));
void USBWakeup_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM8_BRK_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM8_UP_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM8_TRG_COM_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM8_CC_handler(void)__attribute__((weak,alias("Default_handler")));
void ADC3_handler(void)__attribute__((weak,alias("Default_handler")));
void FSMC_handler(void)__attribute__((weak,alias("Default_handler")));
void SDIO_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM5_handler(void)__attribute__((weak,alias("Default_handler")));
void SPI3_handler(void)__attribute__((weak,alias("Default_handler")));
void UART4_handler(void)__attribute__((weak,alias("Default_handler")));
void UART5_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM6_handler(void)__attribute__((weak,alias("Default_handler")));
void TIM7_handler(void)__attribute__((weak,alias("Default_handler")));
void DMA2_Channel1_handler(void)__attribute__((weak,alias("Default_handler")));
void DMA2_Channel2_handler(void)__attribute__((weak,alias("Default_handler")));
void DMA2_Channel3_handler(void)__attribute__((weak,alias("Default_handler")));
void DMA2_Channel4_5_handler(void)__attribute__((weak,alias("Default_handler")));

uint32_t vector_table[] __attribute__((section(".isr_vector")))= {
	(uint32_t)STACK_START,
	(uint32_t)&Reset_handler,
	(uint32_t)&NMI_handler,
	(uint32_t)&HardFault_handler,
	(uint32_t)&MemManage_handler,
	(uint32_t)&BusFault_handler,
	(uint32_t)&UsageFault_handler,
	(uint32_t)0,
	(uint32_t)0,
	(uint32_t)0,
	(uint32_t)0,
	(uint32_t)&SVCall_handler,
	(uint32_t)&DebugMonitor_handler,
	(uint32_t)0,
	(uint32_t)&PendSV_handler,
	(uint32_t)&SysTick_handler,
	(uint32_t)&WWDG_handler,
	(uint32_t)&PVD_handler,
	(uint32_t)&TAMPER_handler,
	(uint32_t)&RTC_handler,
	(uint32_t)&FLASH_handler,
	(uint32_t)&RCC_handler,
	(uint32_t)&EXTI0_handler,
	(uint32_t)&EXTI1_handler,
	(uint32_t)&EXTI2_handler,
	(uint32_t)&EXTI3_handler,
	(uint32_t)&EXTI4_handler,
	(uint32_t)&DMI_Channel1_handler,
	(uint32_t)&DMI_Channel2_handler,
	(uint32_t)&DMI_Channel3_handler,
	(uint32_t)&DMI_Channel4_handler,
	(uint32_t)&DMI_Channel5_handler,
	(uint32_t)&DMI_Channel6_handler,
	(uint32_t)&DMI_Channel7_handler,
	(uint32_t)&ADC1_2_handler,
	(uint32_t)&USB_HP_CAN_TX_handler,
	(uint32_t)&USB_LP_CAN_RX0_handler,
	(uint32_t)&CAN_RX1_handler,
	(uint32_t)&CAN_SCE_handler,
	(uint32_t)&EXTI9_5_handler,
	(uint32_t)&TIM1_BRK,
	(uint32_t)&TIM1_UP_handler,
	(uint32_t)&TIM1_TRG_COM_handler,
	(uint32_t)&TIM1_CC_handler,
	(uint32_t)&TIM2_handler,
	(uint32_t)&TIM3_handler,
	(uint32_t)&TIM4_handler,
	(uint32_t)&I2C1_EV_handler,
	(uint32_t)&I2C1_ER_handler,
	(uint32_t)&I2C2_EV_handler,
	(uint32_t)&I2C2_ER_handler,
	(uint32_t)&SPI1_handler,
	(uint32_t)&SPI2_handler,
	(uint32_t)&USART1_handler,
	(uint32_t)&USART2_handler,
	(uint32_t)&USART3_handler,
	(uint32_t)&EXTI15_10_handler,
	(uint32_t)&RTCAlarm_handler,
	(uint32_t)&USBWakeup_handler,
	(uint32_t)&TIM8_BRK_handler,
	(uint32_t)&TIM8_UP_handler,
	(uint32_t)&TIM8_TRG_COM_handler,
	(uint32_t)&TIM8_CC_handler,
	(uint32_t)&ADC3_handler,
	(uint32_t)&FSMC_handler,
	(uint32_t)&SDIO_handler,
	(uint32_t)&TIM5_handler,
	(uint32_t)&SPI3_handler,
	(uint32_t)&UART4_handler,
	(uint32_t)&UART5_handler,
	(uint32_t)&TIM6_handler,
	(uint32_t)&TIM7_handler,
	(uint32_t)&DMA2_Channel1_handler,
	(uint32_t)&DMA2_Channel2_handler,
	(uint32_t)&DMA2_Channel3_handler,
	(uint32_t)&DMA2_Channel4_5_handler

};

void Default_handler(void){

	while(1);

}

void Reset_handler(void){

	//Initialize .data section 	
	//copy .data section to SRAM
	uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
	uint8_t* pDst = (uint8_t*)&_sdata;  // SRAM
	uint8_t* pSrc = (uint8_t*)&_etext;  // FALSH  // End of the .text section is equavalent to start of the .data section , see in linker script 
	
	for(uint32_t i = 0 ; i<size ; ++i)
		*pDst++ = *pSrc++;

	//Initialize .bss section
	//initialize the .bss section to zero in SARM
	size = (uint32_t)&_ebss - (uint32_t)&_sbss;
	pDst = (uint8_t*)&_sdata;  // SRAM
	for(uint32_t i = 0 ; i<size ; ++i)
		*pDst++ = 0;

	SystemInit();
	main();

}
