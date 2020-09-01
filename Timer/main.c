#include "Timer.h"




void Timer2_IrqTest(void)
{
	
	static uint8_t flag = 0;
	
	flag ^= 0x01;
	
	if(flag == 0)
		GPIOC->BSRR |= GPIO_BSRR_BR13;
	
	else
		GPIOC->BSRR |= GPIO_BSRR_BS13;
	
}




int main()
{
	
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN | RCC_APB2ENR_AFIOEN;
	GPIOC->CRH = 0x00;
	GPIOC->CRH |= GPIO_CRH_MODE13;
	
	
	
	Timer_Init();
	Timer_InterruptEnable(TIMER_2);
	Timer_Enable(TIMER_2);
	Timer2_IRQ(Timer2_IrqTest);
	
	
	
	while(1);
	
}


