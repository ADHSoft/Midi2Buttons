/*******************************************************************************************************************************//**
 *
 * @file		DR_SysTick.c
 * @brief		Descripcion del modulo
 * @date		4 de may. de 2016
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "DR_SysTick.h"
#include "DR_lcd.h"
#include "DR_gpio.h"
#include "PR_Timers.h"
#include "PR_debounce.h"
#include "DR_JoyPS2.h"

void SysTick_Inicializacion ( void )
{
	STRELOAD = ( STCALIB / 4) - 1; 	// 2.5 ms
	STCURR   = 0;

	CLKSOURCE = 1;
	ENABLE    = 1;
	TICKINT   = 1;
}


void SysTick_Handler(void)
{

	TimerCheck();
	Debounce();
	DriverDemoraLCD();
	joy_refresh(1);

}


