/*
 * traffic light.c
 *
 * Created: 16/02/2023 04:14:47 م
 * Author : Abdelrahman Ashraf
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "MCAL/DIO/DIO.h"
#include "HAL/LCD/LCD.h"
#include "MCAL/TIMERS/timer.h"
#include "HAL/LEDS/LED.h"

volatile uint8 counter;
uint8 counter1=5;
uint8 counter2=5;
uint8 counter3=5;
uint8 counter4=5;

int main(void)
{
    LED_vInit(LED_PORT_1,LED_ZERO_PIN);
	LED_vInit(LED_PORT_1,LED_FIRST_PIN);
	LED_vInit(LED_PORT_1,LED_SECOND_PIN);
	LED_vInit(LED_PORT_1,LED_THIRD_PIN);
	LED_vInit(LED_PORT_1,LED_FOURTH_PIN);
	LED_vInit(LED_PORT_1,LED_FIFTH_PIN);
	 LED_vInit(LED_PORT_2,LED_ZERO_PIN);
	 LED_vInit(LED_PORT_2,LED_FIRST_PIN);
	 LED_vInit(LED_PORT_2,LED_SECOND_PIN);
	 LED_vInit(LED_PORT_2,LED_THIRD_PIN);
	 LED_vInit(LED_PORT_2,LED_FOURTH_PIN);
	 LED_vInit(LED_PORT_2,LED_FIFTH_PIN);
	LCD_vInit();
	timer_CTC_init_interrupt();
	
    while (1) 
    {
		 counter1=5;
		 counter2=5;
		 counter3=5;
		 counter4=5;
		 LCD_clearscreen();
		 LCD_vSend_string("CARS ON WEST PATH");
		 LCD_movecursor(2,1);
		 LCD_vSend_string("COULD MOVE NOW");
		 _delay_ms(100);
		 LCD_clearscreen();
		 LCD_vSend_string("remaining 5 sec");
		 LED_vTurnOn(LED_PORT_1,LED_ZERO_PIN); //pin 0 green trrafic light 1
		 LED_vTurnOn(LED_PORT_1,LED_FOURTH_PIN);//pin 4 yellow traffic light 2
		 LED_vTurnOn(LED_PORT_2,LED_SECOND_PIN);//pin 2 red traffic light 3
		 LED_vTurnOn(LED_PORT_2,LED_FIFTH_PIN);//pin 5 red traffic light 4
	
		 while(counter1>0)
		 {
			 if (counter>=10)
			 {
				 counter =0;
				 counter1--;
				 LCD_movecursor(1,10);
				 LCD_vSend_char(' ');
				 LCD_vSend_char((counter1%10)+48);
			 }
		 }
		 _delay_ms(100);
		 
		 LED_vTurnOn(LED_PORT_1,LED_SECOND_PIN); //pin 2
		 LED_vTurnOn(LED_PORT_1,LED_THIRD_PIN); //pin 3
		 LED_vTurnOn(LED_PORT_2,LED_FIRST_PIN);//pin 2 red traffic light 3
		 LED_vTurnOn(LED_PORT_2,LED_FIFTH_PIN);//pin 5 red traffic light 4
		 LED_vTurnOff(LED_PORT_1,LED_ZERO_PIN); //pin 0 green trrafic light 1
		 LED_vTurnOff(LED_PORT_1,LED_FOURTH_PIN);//pin 4 yellow traffic light 2
		 LED_vTurnOff(LED_PORT_2,LED_SECOND_PIN);//pin 2 red traffic light 3
		 LCD_clearscreen();
		 LCD_vSend_string("CARS ON NORTH PATH");
		 LCD_movecursor(2,1);
		 LCD_vSend_string("COULD MOVE NOW");
		 _delay_ms(100);
		 LCD_clearscreen();
		 LCD_vSend_string("remaining 5 sec");
		
		while(counter2>0)
		{
			if (counter>=10)
			{
				counter =0;
				counter2--;
				LCD_movecursor(1,10);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter2%10)+48);
			}
		}
		_delay_ms(100);
		LED_vTurnOn(LED_PORT_1,LED_SECOND_PIN); //pin 2
		LED_vTurnOn(LED_PORT_1,LED_FIFTH_PIN);  //pin 5
		LED_vTurnOn(LED_PORT_2,LED_ZERO_PIN); //pin 0
		LED_vTurnOn(LED_PORT_2,LED_FOURTH_PIN);  //pin 4
		LED_vTurnOff(LED_PORT_1,LED_FOURTH_PIN); //pin 1
		LED_vTurnOff(LED_PORT_2,LED_FIRST_PIN); //pin 4
		LED_vTurnOff(LED_PORT_1,LED_THIRD_PIN);
		LED_vTurnOff(LED_PORT_2,LED_FIFTH_PIN);
		LCD_clearscreen();
		LCD_vSend_string("CAR ON EAST PATH ");
		LCD_movecursor(2,1);
		LCD_vSend_string("COULD MOVE NOW");
		_delay_ms(100);
		LCD_clearscreen();
		LCD_vSend_string("remaining 5 sec");
		
		while(counter3>0)
		{
			if (counter>=10)
			{
				counter =0;
				counter3--;
				LCD_movecursor(1,10);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter3%10)+48);
			}
			
		}
		_delay_ms(100);
		LED_vTurnOn(LED_PORT_1,LED_FIRST_PIN);
		LED_vTurnOn(LED_PORT_2,LED_SECOND_PIN);
		LED_vTurnOn(LED_PORT_2,LED_THIRD_PIN);
		LED_vTurnOff(LED_PORT_1,LED_SECOND_PIN);
		LED_vTurnOff(LED_PORT_1,LED_ZERO_PIN);
		LED_vTurnOff(LED_PORT_1,LED_FOURTH_PIN); //pin 1
		LED_vTurnOff(LED_PORT_2,LED_ZERO_PIN);
		LED_vTurnOff(LED_PORT_2,LED_FOURTH_PIN);  //pin 5
		LCD_clearscreen();
		LCD_vSend_string("CAR ON SOUTH PATH");
		LCD_movecursor(2,1);
		LCD_vSend_string("COULD MOVE NOW");
		_delay_ms(100);
		LCD_clearscreen();
		LCD_vSend_string("remaining 5 sec");
		while(counter4>0)
		{
			if (counter>=10)
			{
				counter4--;
				LCD_movecursor(1,10);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter4%10)+48);
				_delay_ms(100);
			}
		}
		_delay_ms(500);
		
		LED_vTurnOff(LED_PORT_1,LED_FIRST_PIN);
		LED_vTurnOff(LED_PORT_1,LED_FIFTH_PIN);
		LED_vTurnOff(LED_PORT_2,LED_THIRD_PIN);
		LED_vTurnOff(LED_PORT_2,LED_FOURTH_PIN);
		
    }
}

ISR(TIMER0_COMP_vect)
{
	counter++;
}

