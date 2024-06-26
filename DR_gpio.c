/*******************************************************************************************************************************//**
 *
 * @file		Infotronic.c
 * @brief		Drivers de GPIO LPC1769
 * @date		23-03-16
 * @author		Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "DR_gpio.h"

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

/******************************************************************************************************************
 * @fn      void SetDIR ( uint8_t puerto , uint8_t bit , uint8_t dir )
 * @brief   Selecciona si el GPIO sera entrada o salida
 * @param:  puerto: Numero del puerto seleccionado
 * @param:     bit: Numero del bit seleccionado
 * @param:     dir: seleccion entre entrada o salida
 * @return: void
 *****************************************************************************************************************/
void SetDIR ( uint8_t puerto , uint8_t bit , uint8_t dir )
{
	__RW uint32_t *p = ( __RW uint32_t * )  0x2009C000 ;

	if ( dir )
		*( p + puerto * 8 ) = *( p + puerto * 8 ) | ( 1 << bit );
	else
		*( p + puerto * 8 ) = *( p + puerto * 8 ) & ( ~ ( 1 << bit ) );

}

/******************************************************************************************************************
 * @fn      void SetPIN ( uint8_t puerto , uint8_t bit , uint8_t estado )
 * @brief   Activa/Desactiva un pin
 * @param:  puerto: Numero del puerto seleccionado
 * @param:     bit: Numero del bit seleccionado
 * @param:  estado: ON(1) - OFF(0)
 * @return: void
 *****************************************************************************************************************/
void SetPIN ( uint8_t puerto , uint8_t bit , uint8_t estado )
{
	__RW uint32_t *set = ( __RW uint32_t * )  0x2009C018 ;
	__RW uint32_t *clear = ( __RW uint32_t * )  0x2009C01C ;

	if (estado)
		*( set + puerto * 8 ) = *( set + puerto * 8 ) | ( 1 << bit );
	else
		*( clear + puerto * 8 ) = *( clear + puerto * 8 ) | ( 1 << bit );

}

/******************************************************************************************************************
 * @fn      void SetMODE ( uint8_t puerto , uint8_t bit , uint8_t modo )
 * @brief   Selecciona el modo de funcionamiento de un pin especifico
 * @param:  puerto: Numero del puerto seleccionado
 * @param:     bit: Numero del bit seleccionado
 * @param:    modo: Selecciona entre los 4 modos de funcionamiento (PULLUP-REPEATER-NONE-PULLDOWN)
 * @return: void
 *****************************************************************************************************************/
void SetMODE ( uint8_t puerto , uint8_t bit , uint8_t modo )
{
	__RW uint32_t *p = ( __RW uint32_t * )  0x4002C040 ;

	*( p + puerto * 2 + bit / 16 ) &= ~( 0x3  << (  bit     * 2 ) );
	*( p + puerto * 2 + bit / 16 ) |=  ( modo << ( (bit%16) * 2 ) );

}

/******************************************************************************************************************
 * @fn	    uint8_t GetPIN( uint8_t puerto , uint8_t bit , uint8_t actividad )
 * @brief   Obtiene el valor del pin
 * @param:     puerto: Numero del puerto seleccionado
 * @param:        bit: Numero del bit seleccionado
 * @param:  actividad: Estado bajo o estado alto
 * @return: Devuelve el valor del pin
 *****************************************************************************************************************/
uint8_t GetPIN( uint8_t puerto , uint8_t bit , uint8_t actividad )
{
	__RW uint32_t *p = ( __RW uint32_t * )  0x2009C014 ;
	uint8_t r;

	r = ( *( p + puerto * 8 ) >> bit ) & 1;
	if ( actividad )
		return r;
	return !r;
}

