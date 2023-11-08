/*
 * Uc1.c
 *
 *  Created on: Oct 27, 2023
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

void ChannelOne(void);
void ChannelTWo(void);
void ChannelThree(void);
int main() {
	//Switches
	DIO_SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);
	DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_HIGH);

	DIO_SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN3,DIO_HIGH);

	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);
	DIO_SetPinValue(DIO_PORTD,DIO_PIN2,DIO_HIGH);

	DIO_SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	//Enable TX
	USART_Init(9600);

	//INT
	EXTI_INT0ENABLE();
	EXTI_INT0Sense(falling);
	EXTI_INT0SetCallBack(&ChannelOne);

	EXTI_INT1ENABLE();
	EXTI_INT1Sense(falling);
	EXTI_INT1SetCallBack(&ChannelTWo);

	EXTI_INT2ENABLE();
	EXTI_INT2Sense(falling_edge);
	EXTI_INT2SetCallBack(&ChannelThree);

	//GIE
	GIE_Enable();
	while(1)
	{

	}
	return 0;
}

void ChannelOne(void)
{
	USART_Transmit('O');
}
void ChannelTWo(void)
{
	USART_Transmit('F');

}
void ChannelThree(void)
{
	USART_Transmit('X');
}
