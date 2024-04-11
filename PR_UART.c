/*******************************************************************************************************************************//**
 *
 * @file		DR_gpio.c
 * @brief		Descripcion del modulo
 * @date		1 de abr. de 2016
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "PR_UART.h"
#include "DR_UART.h"

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** PROTOTIPO DE FUNCIONES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

 /***********************************************************************************************************************************
 *** FUNCIONES PRIVADAS AL MODULO
 **********************************************************************************************************************************/

 /***********************************************************************************************************************************
 *** FUNCIONES GLOBALES AL MODULO
 **********************************************************************************************************************************/

/*********************************************************************************************
 * @fn     void PushTx( uint8_t dato )
 * @brief  La aplicación pone los datos que se desean transmitir, en el buffer de transmisión
 * @param  dato: valor que se desea transmitir
 * @return void
 ********************************************************************************************/
void UART1_PushTx( uint8_t dato )
{
	if (CantidadTx==TOPE_BUFFER_TX) {
		//buffer lleno
	} else {
		BufferTx[ (IndiceTxStart + CantidadTx) % TOPE_BUFFER_TX ] = dato;

		CantidadTx ++;
		UART1_Iniciar_Envio();
	}
}


/*********************************************************************************************
 * @fn     int16_t UART_PopRx( void )
 * @brief  Saca datos del buffer de recepción para ser leídos desde la aplicación
 * @param  void
 * @return Devuelve el dato que saca del buffer de recepcion
 ********************************************************************************************/
int16_t UART1_PopRx( void )
{
	int16_t dato;

	if( CantidadRx == 0 )
		return -1;

	dato = (uint16_t) BufferRx[ IndiceRxStart ];
	IndiceRxStart ++;
	IndiceRxStart %= TOPE_BUFFER_RX;
	CantidadRx--;

	return dato;
}
