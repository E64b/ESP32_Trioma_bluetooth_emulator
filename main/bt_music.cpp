#include "main.h"
void bt_music(){
	

	if(uiState.Old_Vol!=uiState.Vol){
		a2dp.set_volume(uiState.Vol);
		uiState.Old_Vol=uiState.Vol;
		}
	}