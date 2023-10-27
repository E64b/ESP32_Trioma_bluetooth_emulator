#pragma once
#pragma pack(1, push)

#include "BluetoothA2DPSink.h"
//#include "j1850vpw.h"
#include <math.h> 
#include <stdio.h>
#include <Arduino.h>

#define LED_BUILTIN 13
//#define STORAGE_SIZE 60
//#define RX 19
//#define TX 20

typedef struct{
	uint8_t code;
	uint8_t header;
	uint16_t KeyStatus;
	uint8_t crc;
	} KeyData;

typedef struct{
	uint8_t code;
	uint16_t Control;
	uint8_t crc;
	} CDData;

typedef struct{
	uint16_t Key;
	uint16_t Vol=128;
	uint16_t Old_Vol;
	bool Pong;
	uint32_t timer;
	bool pause;
	} UIState;

extern BluetoothA2DPSink a2dp_sink;
//extern J1850VPW vpw;
extern UIState uiState;

//void EmulatedKeys();
//void readJ1850Messages();
//void ChangerActivate();
void bt_music();

#pragma pack(pop)