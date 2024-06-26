/*******************************************************************************************************************************//**
 *
 * @file		DR_TecladoPS2.h
 * @brief
 * @date
 * @author
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/
#ifndef DRIVERIMPRESORABRAILLE_DR_TECLADOPS2_H_
#define DRIVERIMPRESORABRAILLE_DR_TECLADOPS2_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/
#define TAMANO_RX 50
#define TAMANO_TX 20
/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
extern __RW uint8_t BufferPS2RX[ TAMANO_RX ];
extern __RW uint8_t cantidadRX  ;
extern __RW uint8_t IndexStartRX;

extern __RW uint8_t BufferPS2TX[ TAMANO_TX ];
extern __RW uint8_t cantidadTX  ;
extern __RW uint8_t IndexStartTX;
/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/
void TecladoPS2_Inicializacion( void );

#endif /* DRIVERIMPRESORABRAILLE_DR_TECLADOPS2_H_ */
