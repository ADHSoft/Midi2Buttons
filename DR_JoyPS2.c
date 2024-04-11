/*
 * DR_JoyPS2.c
 *
 *  Created on: 27 de dic. de 2017
 *      Author: int
 */

#include "DR_Infotronic.h"
#include "DR_JoyPS2.h"
#include "DR_pinsel.h"
#include "DR_gpio.h"
#include "DR_timers_hw.h"

__RW uint8_t turn_on=0;

void joy_refresh( uint8_t systick ) {

	#define TICKS_ON 20	//50ms
	#define CTD_BOTONES 6
	static uint16_t ticks[CTD_BOTONES]={0,0,0,0,0,0};
	static uint8_t on=0;
	uint8_t i;

	for (i=0;i<CTD_BOTONES;i++) {

		if ( ((on>>i)&1) ==1 && systick==1 ) {	//contar tiempo, solo si se llamo por systick
			ticks[i]++;
			if (ticks[i]==TICKS_ON) {
				ticks[i]=0;
				on&=~(1<<i);
			}
		} else {
			if ( ((turn_on>>i)&1) ==1 ) {	//prender
				on|=(1<<i);
			}
		}
	}

	turn_on=0;

	SetPIN(EXPANSION0, !((on&0b00000001)>>0 ));
	SetPIN(EXPANSION1, !((on&0b00000010)>>1 ));
	SetPIN(EXPANSION2, !((on&0b00000100)>>2 ));
	SetPIN(EXPANSION3, !((on&0b00001000)>>3 ));
	SetPIN(EXPANSION4, !((on&0b00010000)>>4 ));
	SetPIN(EXPANSION5, !((on&0b00100000)>>5 ));

}



void joy_init(){

	SetPINSEL( EXPANSION0 , FUNCION_GPIO );
	SetDIR   ( EXPANSION0 , SALIDA );
	SetPIN   ( EXPANSION0 , OFF);

	SetPINSEL( EXPANSION1 , FUNCION_GPIO );
	SetDIR   ( EXPANSION1 , SALIDA );
	SetPIN   ( EXPANSION1 , OFF);

	SetPINSEL( EXPANSION2 , FUNCION_GPIO );
	SetDIR   ( EXPANSION2 , SALIDA );
	SetPIN   ( EXPANSION2 , OFF);

	SetPINSEL( EXPANSION3 , FUNCION_GPIO );
	SetDIR   ( EXPANSION3 , SALIDA );
	SetPIN   ( EXPANSION3 , OFF);

	SetPINSEL( EXPANSION4 , FUNCION_GPIO );
	SetDIR   ( EXPANSION4 , SALIDA );
	SetPIN   ( EXPANSION4 , OFF);

	SetPINSEL( EXPANSION5 , FUNCION_GPIO );
	SetDIR   ( EXPANSION5 , SALIDA );
	SetPIN   ( EXPANSION5 , OFF);

}








//void a( void )
//{
//	#define ENVIAR 0
//	#define REPOSO 1
//	#define RECIBIR 2
//
//	#define BAJAR_CLK SetPIN(PIN_CLOCK_OUT,TRUE);clk=0
//	#define SUBIR_CLK SetPIN(PIN_CLOCK_OUT,FALSE);clk=1
//	#define DATA_ON SetPIN(PIN_DATA_OUT,FALSE)
//	#define DATA_OFF SetPIN(PIN_DATA_OUT,TRUE)
//
//	static int8_t estado=REPOSO,bit=0,clk=1,byte_a_enviar;
//
//	return;
//	/*
//	switch(estado) {
//		case REPOSO:
//			if (PIN_CLOCK_IN==1) {
//				if ( cantidad_buffer_joy_tx!=0 ) {
//					estado=ENVIAR;
//					bit=0;
//				}
//			} else {
//				estado=RECIBIR;
//			}
//			break;
//		case ENVIAR:
//			if (clk==1) {
//				BAJAR_CLK;
//			} else {
//				//lsb first
//				if (byte_a_enviar&1) {
//					DATA_ON;
//				} else {
//					DATA_OFF;
//				}
//				byte_a_enviar>>=1;
//
//				bit++;
//				if (bit==8) {
//					bit=0;
//
//				}
//
//				SUBIR_CLK;
//			}
//
//			break;
//	}
//	*/
//
//
//	TIMER0.IR |= 1;		//limpiar flag de interrupcion match0 antes de salir de la funcion
//}
//
//void spi_init(){
//
//		PCONP |= ( 1 << 8 ); 		// Encender SPI, por las dudas (por reset esta encendido)
//		PCLKSEL0 &= ~( 3 << 16 );    // Clock for timer = CCLK/4=25MHz
//
//		SetPINSEL( SPI_MOSI , 2 );
//		SetPINSEL( SPI_MISO , 2 );
//		SetPINSEL( SPI_SSEL , 2 );
//		SetPINSEL( SPI_SCK , 2 );
//
//		//S0SPINT
//		*((uint32_t*) 0x4002001C)|=1;
//
//		//ISER (NVIC)
//		ISER[0] |= 1 << 13;
//
//		//S0SPCR A hardware interrupt is generated each time the SPIF or MODF bits are activated.
//		*((uint32_t*)0x40020000)|=1<<7;
//
//}


//void SPI_IRQHandler(){
//
//	uint8_t recibir;
//
//	recibir=*((uint32_t*)0x40020008);
//}















