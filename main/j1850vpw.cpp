#include "main.h"

void handleKeyData(KeyData* pKeyData){
	auto KeyStatus=pKeyData->KeyStatus;
	uiState.Key=KeyStatus;
	}
/*
void handleCDData(CDData* pCDData){
	auto Control=pCDData->Control;
	if(Control==0x0f23){
		uiState.Pong=true;
		}
	}

void ChangerActivate(){
	static uint8_t sendBuffCD[5]={0x8d, 0x93, 0x01, 0x02, 0x10};

	if((uiState.Pong==true)and(millis()-uiState.timer>=250)){
		uiState.timer=millis();
		vpw.send(sendBuffCD, sizeof(sendBuffCD));
		}
	}
*/
void readJ1850Messages(){
	static uint8_t buff[BS];
	static uint8_t dataSize;

	while(dataSize=vpw.tryGetReceivedFrame(buff)){
		switch(buff[0]){
				case 0x3D:
					handleKeyData((KeyData*)buff);
					break;
					/*
					case 0x8D:
						 handleCDData((CDData*)buff);
						 break;*/

			}
		}
	}