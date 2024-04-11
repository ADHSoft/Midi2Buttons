/*******************************************************************************************************************************//**
 *
 * @file		DR_nombre.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		1 de abr. de 2016
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef AP_PS2_H_
#define AP_PS2_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "DR_tipos.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/************************ Identificadores codigo extendido *********************************/
#define 	BLOQ_MAYUS			0x58
#define 	TAB					0x0d
#define 	ENTER				0x5a
#define 	BACKSPACE			0x66
#define 	ESC				    0x76
#define 	F1		    		0x05
#define 	F2		    		0x06
#define 	MAS_CALC		    0x79
#define 	MENOS_CALC		    0x7b
#define 	F5		    		0x03
#define 	F6		    		0x0b
#define 	F8		    		0x0a
#define 	F9		    		0x01
#define 	F10		    		0x09
#define 	F11		    		0x78
#define 	F12		    		0x07
#define 	UNO		    		0x69
#define 	DOS		    		0x72
#define 	TRES		    	0x7a
#define 	CUATRO		    	0x6b
#define 	CINCO		    	0x73
#define 	SEIS		    	0x74

//que no coincidan con letras
#define 	INSERT				0x70	// 0xe070
#define 	FIN					0x69	// 0xe069
#define 	INICIO				0x6c	// 0xe06c
#define 	FLE_ARR		    	0x75	// 0xe075
#define 	FLE_ABA		    	0x72	// 0xe072
#define 	FLE_IZQ		    	0x6b	// 0xe06b
#define 	FLE_DER		    	0x74	// 0xe074
#define 	PG_DN		    	0x7A	// 0xe074

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
extern __RW uint8_t Tecla_Letra, Tecla_Funcion;

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/
void decode_PS2( uint8_t code_PS2 );
void interpretar_buffer_PS2( uint8_t reset );

#endif /* AP_PS2_H_ */
