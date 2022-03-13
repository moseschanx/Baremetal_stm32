#include <stdint.h>

#define SRAM_START	 0x20000000U
#define SRAM_SIZE 	 (20U * 1024U)
#define SRAM_END  	 (SRAM_START + SRAM_SIZE)
#define STACK_START	 SRAM_END 

extern int main(void);

void Reset_handler(void)__attribute__((section("random_section")));

void NMI_handler(void)__attribute__((alias("Default_handler")));
void HardFault_handler(void)__attribute__((alias("Default_handler")));
void MemManage_handler(void)__attribute__((alias("Default_handler")));
void BusFault_handler(void)__attribute__((alias("Default_handler")));
void UsageFault_handler(void)__attribute__((alias("Default_handler")));
void SVCall_handler(void)__attribute__((alias("Default_handler")));
void DebugMonitor_handler(void)__attribute__((alias("Default_handler")));
void PendSV_handler(void)__attribute__((alias("Default_handler")));
void SysTick_handler(void)__attribute__((alias("Default_handler")));
void WWDG_handler(void)__attribute__((alias("Default_handler")));
void PVD_handler(void)__attribute__((alias("Default_handler")));
void TAMPER_handler(void)__attribute__((alias("Default_handler")));
void RTC_handler(void)__attribute__((alias("Default_handler")));
void FLASH_handler(void)__attribute__((alias("Default_handler")));
void RCC_handler(void)__attribute__((alias("Default_handler")));
void EXTI0_handler(void)__attribute__((alias("Default_handler")));
void EXTI1_handler(void)__attribute__((alias("Default_handler")));
void EXTI2_handler(void)__attribute__((alias("Default_handler")));
void EXTI3_handler(void)__attribute__((alias("Default_handler")));
void EXTI4_handler(void)__attribute__((alias("Default_handler")));
void DMI_Channel1_handler(void)__attribute__((alias("Default_handler")));
void DMI_Channel2_handler(void)__attribute__((alias("Default_handler")));
void DMI_Channel3_handler(void)__attribute__((alias("Default_handler")));
void DMI_Channel4_handler(void)__attribute__((alias("Default_handler")));
void DMI_Channel5_handler(void)__attribute__((alias("Default_handler")));
void DMI_Channel6_handler(void)__attribute__((alias("Default_handler")));
void DMI_Channel7_handler(void)__attribute__((alias("Default_handler")));
void ADC1_2_handler(void)__attribute__((alias("Default_handler")));
void USB_HP_CAN_TX_handler(void)__attribute__((alias("Default_handler")));
void USB_LP_CAN_RX0_handler(void)__attribute__((alias("Default_handler")));
void CAN_RX1_handler(void)__attribute__((alias("Default_handler")));
void CAN_SCE_handler(void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));

void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));

void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));

void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));
void (void)__attribute__((alias("Default_handler")));


uint32_t vector_table[] __attribute__((section(".isr_vector")))= {
	STACK_START,
	(uint32_t)&Reset_handler,
	(uint32_t)&NMI_handler,
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	(uint32_t),
	




};

void Default_handler(void){

}


void Reset_handler(void){

	main();

}

void NMI_handler(void){

	while(1);


}
