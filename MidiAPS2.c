//Midi Drum Kit converter to Hardware Buttons - 2017 ADHSoft0@gmail.com

//EXP18 pin 3 desde derecha

#include <DR_Inicializacion.h>
#include <DR_tipos.h>

#include "PR_Timers.h"
#include "PR_lcd.h"
#include "PR_debounce.h"
#include "PR_UART.h"
#include "DR_JoyPS2.h"
#include "DR_Infotronic.h"

#define	EV_WAIT_TIME 20
#define EV_LED 21
#define EV_MIDI_TIMEOUT 22

void bitswap(uint8_t *);
void reset_led ();

int main(void)
{

	//uint8_t turn_on2=1;
	uint8_t byte=0,message[3],t=0,pad=10;
	int16_t data;
	char txt[10]="         ";

	//50 doesn't count
	#define CHANNEL (10-1)
	#define NOTE_ON 0x90
	#define NOTE_OFF 0x80

	#define NOTE1 50
	#define NOTE2 0x28
	#define NOTE3 0x39
	#define NOTE4 0x23
	#define NOTE5 0x2a
	#define NOTE6 0x30

	#define MIN_VEL 10	//ignored

	#define LR SetPIN(RGB_R,1)
	#define LG SetPIN(RGB_G,1)
	#define LB SetPIN(RGB_B,1)


	Initialize();

    // 1 sec delay
    TimerStart(EV_WAIT_TIME,11,DEC,NULL);
    while(TimerGet(EV_WAIT_TIME)!=0) {};
	TimerStop(EV_WAIT_TIME);

	while(1) {

		//Execute timer events
		TimerEvent();

//	    TimerStart(EV_ESPERA,2,DEC,NULL);
//	    while(TimerGet(EV_ESPERA)!=0) {};
//		TimerStop(EV_ESPERA);

		data=UART1_PopRx();
		if (data!=-1) {
			if (TimerGet(EV_MIDI_TIMEOUT)==0) byte=0;
			if (data==(NOTE_ON+CHANNEL)) byte=0;
			switch (byte) {
				case 0:
					TimerStart(EV_MIDI_TIMEOUT,2,DEC,NULL);
					message[0]=data;
					byte++;
					break;
				case 1:
					TimerStart(EV_LED,1,DEC,reset_led);
					message[1]=data;

					if (message[0]== (NOTE_ON+CHANNEL) ) {
						switch (message[1]) {
							case NOTE1:	//high tom
								turn_on|=1;
								LG;
								break;
							case NOTE2:	//snare
								turn_on|=2;
								LR;
								LG;
								break;
							case NOTE3:	//crash
								turn_on|=4;
								LB;
								break;
							case NOTE4:		//pedal
								turn_on|=8;
								LR;
								LB;
								break;
							case NOTE5:	//hi hat
								turn_on|=16;
								LB;
								LG;
								break;
							case NOTE6:	//low tom
								turn_on|=32;
								LR;
								break;
							default: txt[0]=((message[1]&0xf0)>>4)+0x30;
								if (txt[0]>'9') txt[0]+=7;
								txt[1]=(message[1]&0x0f)+0x30;
								if (txt[1]>'9') txt[1]+=7;
								lcdprintf(NULL,txt);
							break;
						}
					}
					byte++;
					joy_refresh(0);
					break;
				case 2:
					message[2]=data;
					//ignore velocity

					TimerStop(EV_MIDI_TIMEOUT);


					break;

			}
		}

	}

}

void bitswap(uint8_t * dato){
	uint8_t i, out=0;

	for (i=0;i<8;i++) {
		if ((*dato >> i) & 1) out|=(1<<i);
	}

	*dato=out;

}



void reset_led (){
	SetPIN(RGB_R,0);
	SetPIN(RGB_G,0);
	SetPIN(RGB_B,0);
}

