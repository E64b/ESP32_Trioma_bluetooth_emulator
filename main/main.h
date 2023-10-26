#pragma once
#pragma pack(1, push)

#include "/lib/BluetoothA2DPSink.h"
#include "lib/j1850vpw.h"
#include <math.h> 
#include <stdio.h>

#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif

#define STORAGE_SIZE 60
#define RX 19
#define TX 20

typedef struct{
	uint8_t code;
	uint8_t header;
	uint16_t KeyStatus;
	uint8_t crc;
	} KeyData;

typedef struct{
	uint16_t Key;
	uint16_t Vol=30;
	uint16_t Old_Vol;
	bool Pong;
	uint32_t timer;
	} UIState;

typedef struct{
	uint8_t code;
	uint16_t Control;
	uint8_t crc;
	} CDData;

extern BluetoothA2DPSink a2dp;
extern J1850VPW vpw;
extern UIState uiState;

void EmulatedKeys();
void readJ1850Messages();
//void ChangerActivate();
void bt_music();

#pragma pack(pop)