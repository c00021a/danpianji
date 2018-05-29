#include "LPC11xx.h"
int i=0;
void LedInit(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<16);
	LPC_IOCON->PIO2_0&=~0X07;
	LPC_IOCON->PIO2_0 |=0X00;
	LPC_IOCON->PIO2_1&=~0X07;
	LPC_IOCON->PIO2_1 |=0X00;
	LPC_IOCON->PIO2_2&=~0X07;
	LPC_IOCON->PIO2_2 |=0X00;
	LPC_IOCON->PIO2_3&=~0X07;
	LPC_IOCON->PIO2_3 |=0X00;
	LPC_IOCON->PIO2_4&=~0X07;
	LPC_IOCON->PIO2_4 |=0X00;
	LPC_IOCON->PIO2_5&=~0X07;
	LPC_IOCON->PIO2_5 |=0X00;
	LPC_IOCON->PIO2_6&=~0X07;
	LPC_IOCON->PIO2_6 |=0X00;
	LPC_IOCON->PIO2_7&=~0X07;
	LPC_IOCON->PIO2_7 |=0X00;
	
	LPC_SYSCON->SYSAHBCLKCTRL &= ~(1<<16);
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);
	LPC_GPIO2->DIR |= (1<<0);
	LPC_GPIO2->DATA |= (1<<0);
	LPC_GPIO2->DIR |= (1<<1);
	LPC_GPIO2->DATA |= (1<<1);
	LPC_GPIO2->DIR |= (1<<2);
	LPC_GPIO2->DATA |= (1<<2);
	LPC_GPIO2->DIR |= (1<<3);
	LPC_GPIO2->DATA |= (1<<3);
	LPC_GPIO2->DIR |= (1<<4);
	LPC_GPIO2->DATA |= (1<<4);
	LPC_GPIO2->DIR |= (1<<5);
	LPC_GPIO2->DATA |= (1<<5);
	LPC_GPIO2->DIR |= (1<<6);
	LPC_GPIO2->DATA |= (1<<6);
	LPC_GPIO2->DIR |= (1<<7);
	LPC_GPIO2->DATA |= (1<<7);

}
void TIMER32_0_IRQHandler(void)
{
	LPC_TMR32B0->IR = 0x01;
	LPC_GPIO2->DATA |= 0xff;
	LPC_GPIO2->DATA &= ~(1<<i);
	i++;
  if(i==8)
	i=0;

}
void Timer0Init(void)
{
	LPC_SYSCON->SYSAHBCLKCTRL |= (1<<9);
	LPC_TMR32B0->IR= 0X01;
	LPC_TMR32B0->PR= 0;
	LPC_TMR32B0->MCR= 0X03;
	LPC_TMR32B0->MR0= SystemCoreClock/2;
	LPC_TMR32B0->TCR= 0X01;
	NVIC_EnableIRQ(TIMER_32_0_IRQn);
}
int main(void)
{
	LedInit();
	Timer0Init();
	while(1);
	
}