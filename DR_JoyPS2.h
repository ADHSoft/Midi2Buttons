/*
 * DR_JoyPS2.h
 *
 *  Created on: 27 de dic. de 2017
 *      Author: int
 */

#ifndef DR_JOYPS2_H_
#define DR_JOYPS2_H_

#include "DR_tipos.h"

//#define		TAMANO_BUFFER_JOY_TX		150
//
//extern __RW uint8_t BufferJoy[ TAMANO_BUFFER_JOY_TX ];
//extern __RW int32_t inicio_buffer_joy_tx ;
//extern __RW int32_t cantidad_buffer_joy_tx ;

extern __RW uint8_t turn_on;

void joy_init();
void joy_refresh(uint8_t);

#endif /* DR_JOYPS2_H_ */
