/*******************************************************************************************************************************//**
 *
 * @file		PR_Timers.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		2 de jun. de 2017
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef PRIMITIVAS_PR_TIMERS_H_
#define PRIMITIVAS_PR_TIMERS_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "DR_tipos.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/
#define 	DEC			0
#define 	SEG			1
#define 	MIN			2

#define 	RUN			0
#define 	PAUSE		1

#define 	N_TIMERS		30

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/
typedef void ( *TmrHandler )( void );

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
// extern tipo nombreVariable;

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/
void TimerStart ( uint8_t event , uint32_t time , uint8_t base , TmrHandler handler ) ;
void TimerSet   ( uint8_t event , uint32_t time ) ;
void TimerStop  ( uint8_t event ) ;
void TimerClose ( void ) ;
void TimerCheck ( void ) ;
void TimerEvent ( void ) ;
void TimerStandBy ( uint8_t event , uint8_t accion ) ;
uint32_t TimerGet ( uint8_t event ) ;

#endif /* PRIMITIVAS_PR_TIMERS_H_ */



