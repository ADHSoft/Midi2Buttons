/*******************************************************************************************************************************//**
 *
 * @file		Infotronic.h
 * @brief		Declaracion de tipos Globales
 * @date		23-03-16
 * @author		Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef DR_TIPOS_H_
#define DR_TIPOS_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/
#define     __R					volatile const  	// !< Modificador para solo lectura
#define 	__W     			volatile 	       	// !<  Modificador para solo escritura
#define 	__RW				volatile           	// !< Modificador lectura / escritura

#define 	ON					1
#define 	OFF					0

#define 	NULL				(( void *) 0)

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

typedef		unsigned int		uint32_t;
typedef		short unsigned int	uint16_t;
typedef		unsigned char		uint8_t ;
typedef		int					int32_t;
typedef		short int			int16_t;
typedef		char				int8_t;

typedef enum { FALSE , TRUE } bool_t;

typedef struct
{
	const uint8_t* pcm_data;	//check const
	uint32_t Size;
} audio_t;

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/

#endif /* DR_TIPOS_H_ */
