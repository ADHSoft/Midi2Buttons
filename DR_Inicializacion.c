
/*******************************************************************************************************************************//**
 *
 * @file		Inicializacion.c
 * @brief		Inicializaciones del Kit de Info II Infotronic
 * @date		23/03/16
 * @author		Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "DR_Infotronic.h"
#include "DR_Inicializacion.h"
#include "DR_pinsel.h"
#include "DR_lcd.h"
#include "DR_TecladoPS2.h"
#include "DR_UART.h"
#include "DR_JoyPS2.h"

/******************************************************************************************************************
 * @fn      void Ini_Infotronic( void )
 * @brief   Inicializa las GPIO de la placa Infotronic
 * @param:  void
 * @return: void
 *****************************************************************************************************************/
void Ini_Infotronic( void )
{

	SetPINSEL( SW1 , FUNCION_GPIO );	//teclado infotronic
	SetDIR   ( SW1 , ENTRADA );
	SetPINSEL( SW2 , FUNCION_GPIO );	//teclado infotronic
	SetDIR   ( SW2 , ENTRADA );
	SetPINSEL( SW3 , FUNCION_GPIO );	//teclado infotronic
	SetDIR   ( SW3 , ENTRADA );
	SetPINSEL( SW4 , FUNCION_GPIO );	//teclado infotronic
	SetDIR   ( SW4 , ENTRADA );
	SetPINSEL( SW5 , FUNCION_GPIO );	//teclado infotronic
	SetDIR   ( SW5 , ENTRADA );

	//anti ruidos y luces
	SetPINSEL( BUZZER , FUNCION_GPIO );	//buzzer
	SetDIR   ( BUZZER , SALIDA );
	SetPIN   ( BUZZER , ON );

	SetPINSEL( RGB_R , FUNCION_GPIO );	//R
	SetDIR   ( RGB_R , SALIDA );
	SetPIN   ( RGB_R , OFF );

	SetPINSEL( RGB_G , FUNCION_GPIO );	//G
	SetDIR   ( RGB_G , SALIDA );
	SetPIN   ( RGB_G , OFF );

	SetPINSEL( RGB_B , FUNCION_GPIO );	//B
	SetDIR   ( RGB_B , SALIDA );
	SetPIN   ( RGB_B , OFF );

	SetPINSEL( RELAY1 , FUNCION_GPIO );
	SetPINSEL( RELAY2 , FUNCION_GPIO );
	SetPINSEL( RELAY3 , FUNCION_GPIO );
	SetPINSEL( RELAY4 , FUNCION_GPIO );

	SetDIR( RELAY1 , SALIDA );
	SetDIR( RELAY2 , SALIDA );
	SetDIR( RELAY3 , SALIDA );
	SetDIR( RELAY4 , SALIDA );

	SetPIN( RELAY1 , OFF );
	SetPIN( RELAY2 , OFF );
	SetPIN( RELAY3 , OFF );
	SetPIN( RELAY4 , OFF );
}

/***********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 **********************************************************************************************************************************/

/******************************************************************************************************************
 * @fn      void Inicializacion( void )
 * @brief   Inicializacion general. Esta funcion llama a la mayoria de las funciones de inicializacion
 * @param:  void
 * @return: void
 *****************************************************************************************************************/
void Initialize( void )
{
	//!< LPC1769
	InitPLL();		//!< Configuro en primer lugar el PLL:Estabiliza el oscilador interno del micro en 100MHz

	Ini_Infotronic();

	lcd_inicializacion();

	SysTick_Inicializacion();

	joy_init();

	InitUART1();

}
