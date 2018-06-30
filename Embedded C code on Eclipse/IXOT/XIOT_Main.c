/*
 *  Author: Mahmoud Elatrby
 *  XIOT Internship Task
 */
/*####################Files Includes & pre-Defines Section####################*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include "lcd.h"
#include "adc.h"
#include "uart.h"
#define NUMBER_OF_OVERFLOWS_PER_HALF_SECOND 2

/*####################Functions Prototypes Section####################*/
void INT0_Init(void);
void timer0_init_normal_mode(void);
void stream_temp(void);

/*####################Global Variable Section####################*/
uint8 g_tick=0;

/*####################Interrupt service routines Section####################*/
/* ISR executed when INT0 occures due to button click */
ISR(INT0_vect)
{
	CLEAR_BIT(SREG,7);  // Disable interrupts by clearing I-bit
	PORTB|=(1<<PB0);	// out 1 on PB0 pin : Led on
	LCD_clearScreen();	//Clear LCD screen;
	LCD_displayStringRowColumn(0,0,"Pressed");
	LCD_displayStringRowColumn(1,0,"LED ON");
	UART_sendString(" Pressed, LED ON ");	//streaming on Serial monitor
	SET_BIT(SREG,7);   // Enable interrupts by setting I-bit
}
/* ISR executed when Timer0 finish counting */
ISR(TIMER0_OVF_vect)
{
	g_tick++;
	if(g_tick == 6*NUMBER_OF_OVERFLOWS_PER_HALF_SECOND)
	{
		stream_temp();
		g_tick = 0; //clear the tick counter again to count a new 0.5 second
	}
}

/*####################Functions Implementation Section####################*/
/* Main function */
int main(void)
{
	INT0_Init();/* initialize INT0 */
	ADC_init(); /* initialize ADC */
	LCD_init(); /* initialize LCD */
	ADC_init(); /* initialize ADC */
	UART_init(); /* initialize UART */
	timer0_init_normal_mode(); /* initialize Timer0 */

	SET_BIT(DDRB,PB0);    // Configure pin PC0 in PORTC as output pin // led
	CLEAR_BIT(PORTB,PB0); // Initialization Led is off at the beginning(Negative Logic)
	UART_sendString(" Not Pressed, LED OFF "); //streaming on Serial monitor
	CLEAR_BIT(PORTB,PB0);	//Clear PB0 : LED OFF
	LCD_clearScreen(); //clear LCD Screen from any garbage on Data memory of LCD;
	LCD_displayStringRowColumn(0,0,"Not Pressed");
	LCD_displayStringRowColumn(1,0,"LED OFF");


    while(1)
    {
    }
}
/* External INT0 enable and configuration function */
void INT0_Init(void)
{
	CLEAR_BIT(SREG,7);                   // Disable interrupts by clearing I-bit
	DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	SET_BIT(GICR,INT0);                // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SET_BIT(SREG,7);                    // Enable interrupts by setting I-bit
}
void timer0_init_normal_mode(void)
{
	TCNT0 = 0; //timer initial value
	TIMSK |= (1<<TOIE0); //enable overflow interrupt
	TCCR0 = (1<<FOC0) | (1<<CS02) | (1<<CS00);
}
/* Streaming temperature on LCD function */
void stream_temp(void)
{
	uint32 temp=0;
	temp = ADC_read(0); //reading ADC value
	temp = (temp*150*5)/(1023*1.5);	//actual value of temp.
	LCD_clearScreen();
	LCD_displayStringRowColumn(0,0,"Temp is ");
	LCD_goToRowColumn(0,8);
	LCD_intgerToString(temp); //display temp. on LCD
	LCD_displayStringRowColumn(0,11,"C");
}
