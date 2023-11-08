/*
 * main.c
 *
 *  Created on: Oct 3, 2023
 *      Author: Lenovo
 */

#include <util/delay.h>.
#include <avr/interrupt.h>

#define F_CPU 8000000UL
#include "../MCAL/DIO-DRIVER/DIO_MCAL_Interface.h"
#include "../MCAL/GIE-DRIVER/GIE_MCAL_Interface.h"
#include "../MCAL/EXTI-DRIVER/EXTI_MCAL_Interface.h"
#include "../MCAL/ADC-DRIVER/ADC_MCAL_Interface.h"
#include "../MCAL/TMR-DRIVER/TMR_MCAL_Interface.h"
#include "../MCAL/USART-DRIVER/USART_MCAL_Interface.h"

#include "../HAL/LCD-DRIVER/LCD_HAL_Interface.h"
#include "../HAL/SEGMENT_DRIVER/SEG_HAL_Interface.h"
#include "../HAL/KPD_DRIVER/KPD_HAL_Interface.h"
#include "../HAL/LM_SENSOR-DIRVER/LM_HAL_Interface.h"
#include "../HAL/STEPPER_MOTOR-DRIVER/STEP_HAL_Interface.h"

#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"


int main() {
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_OUTPUT);
	USART_Init(9600);
	u8 rec;
	while(1)
	{
		rec = USART_Recieve();
		if(rec == 'O')
		{
			DIO_SetPinValue(DIO_PORTC,DIO_PIN0,DIO_HIGH);
			_delay_ms(1000);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN1,DIO_LOW);
			_delay_ms(1000);
		}
		if(rec == 'F')
		{
			DIO_SetPinValue(DIO_PORTC,DIO_PIN0,DIO_LOW);
			_delay_ms(1000);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN1,DIO_HIGH);
			_delay_ms(1000);
		}
		if(rec == 'X')
		{
			DIO_SetPinValue(DIO_PORTC,DIO_PIN0,DIO_LOW);
			_delay_ms(1000);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN1,DIO_LOW);
			_delay_ms(1000);
		}
	}




	return 0;
}
