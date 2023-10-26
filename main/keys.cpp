#include "main.h"

void EmulatedKeys(){
	switch(uiState.Key){
			case 0x0000: //All buttons released

				break;

			case 0x0400: //Vol Up
				uiState.Vol++;
				break;

			case 0x0200: //Vol Down
				uiState.Vol--;
				break;

			case 0x0002: //Play
				if(a2dp.pause()){
					a2dp.play();
					} else{
					a2dp.pause();
					}
				break;

			case 0x2000: //Next
				a2dp.next();
				break;

			case 0x0080: //SRC

				break;

			case 0x1000: //Previous
				a2dp.previous();
				break;
		}
	}