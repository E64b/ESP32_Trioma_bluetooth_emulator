#include "SoundData.h"

#define SOUND_DATA "SOUND_DATA"

bool SoundData::doLoop(){
	return automatic_loop;
	}
void SoundData::setLoop(bool loop){
	automatic_loop=loop;
	}

TwoChannelSoundData::TwoChannelSoundData(Frame* data, int32_t len, bool loop){
	setData(data, len);
	setLoop(loop);
	}

TwoChannelSoundData::TwoChannelSoundData(bool loop){
	setLoop(loop);
	}


void TwoChannelSoundData::setData(Frame* data, int32_t len){
	this->len=len;
	this->data=data;
	}

void TwoChannelSoundData::setDataRaw(uint8_t* data, int32_t len){
	this->len=len/4;
	this->data=(Frame*)data;
	}


int32_t TwoChannelSoundData::getData(int32_t pos, int32_t len, Frame* data){
	//ESP_LOGD(SOUND_DATA, "x%x - pos: %d / len: %d", __func__, pos, len);
	int result_len=std::min(len, this->len-pos);
	for(int32_t j=0; j<result_len; j++){
		data[j]=this->data[pos+j];
		}
	return result_len;
	}

int32_t TwoChannelSoundData::getData(int32_t pos, Frame& frame){
	int32_t result=0;
	if(pos<this->len){
		result=1;
		frame.channel1=this->data[pos].channel1;
		frame.channel2=this->data[pos].channel2;
		}
	return result;
	}

int32_t TwoChannelSoundData::get2ChannelData(int32_t pos, int32_t len, uint8_t* data){
	//ESP_LOGD(SOUND_DATA, "x%x - pos: %d / len: %d", __func__, pos, len);
	return getData(pos/4, len/4, (Frame*)data)*4;
	}

OneChannelSoundData::OneChannelSoundData(int16_t* data, int32_t len, bool loop, ChannelInfo channelInfo){
	this->channelInfo=channelInfo;
	setData(data, len);
	setLoop(loop);
	}

OneChannelSoundData::OneChannelSoundData(bool loop, ChannelInfo channelInfo){
	this->channelInfo=channelInfo;
	setLoop(loop);
	}

void OneChannelSoundData::setData(int16_t* data, int32_t len){
	this->len=len;
	this->data=data;
	}

void OneChannelSoundData::setDataRaw(uint8_t* data, int32_t lenBytes){
	this->len=lenBytes/sizeof(int16_t);
	this->data=(int16_t*)data;
	}

int32_t OneChannelSoundData::getData(int32_t pos, int32_t len, int16_t* data){
	int result_len=std::min(len, this->len-pos);
	for(int32_t j=0; j<result_len; j++){
		data[j]=this->data[pos+j];
		}
	return result_len;
	}

int32_t OneChannelSoundData::get2ChannelData(int32_t pos, int32_t len, uint8_t* data){
	//ESP_LOGD(SOUND_DATA, "x%x - pos: %d / len: %d", __func__, pos, len);
	Frame* result_data=(Frame*)data;
	int32_t frame_count=len/4;
	int32_t frame_start=pos/4;
	int32_t result_len=0;
	int32_t frame_pos;

	for(int32_t j=0; j<frame_count; j++){
		frame_pos=frame_start+j;
		if(getData(frame_pos, result_data[j])==0)
			break;
		result_len+=4;
		}
	return result_len;
	}

int32_t OneChannelSoundData::getData(int32_t pos, Frame& frame){
	int32_t result=0;
	if(pos<this->len){
		result=1;
		switch(channelInfo){
				case Left:
					frame.channel1=this->data[pos];
					frame.channel2=0;
					break;
				case Right:
					frame.channel1=0;
					frame.channel2=this->data[pos];
					break;

				case Both:
				default:
					frame.channel1=this->data[pos];
					frame.channel2=frame.channel1;
					break;
			}
		}
	return result;
	}

OneChannel8BitSoundData::OneChannel8BitSoundData(int8_t* data, int32_t len, bool loop, ChannelInfo channelInfo){
	this->channelInfo=channelInfo;
	setData(data, len);
	setLoop(loop);
	}

OneChannel8BitSoundData::OneChannel8BitSoundData(bool loop, ChannelInfo channelInfo){
	this->channelInfo=channelInfo;
	setLoop(loop);
	}

void OneChannel8BitSoundData::setData(int8_t* data, int32_t len){
	this->len=len;
	this->data=data;
	}

void OneChannel8BitSoundData::setDataRaw(uint8_t* data, int32_t lenBytes){
	this->len=lenBytes/sizeof(int8_t);
	this->data=(int8_t*)data;
	}

int32_t OneChannel8BitSoundData::getData(int32_t pos, int32_t len, int8_t* data){
	int result_len=std::min(len, this->len-pos);
	for(int32_t j=0; j<result_len; j++){
		data[j]=this->data[pos+j];
		}
	return result_len;
	}

int32_t OneChannel8BitSoundData::get2ChannelData(int32_t pos, int32_t len, uint8_t* data){
	//ESP_LOGD(SOUND_DATA, "x%x - pos: %d / len: %d", __func__, pos, len);
	Frame* result_data=(Frame*)data;
	int32_t frame_count=len/4;
	int32_t frame_start=pos/4;
	int32_t result_len=0;
	int32_t frame_pos;

	for(int32_t j=0; j<frame_count; j++){
		frame_pos=frame_start+j;
		if(getData(frame_pos, result_data[j])==0)
			break;
		result_len+=4;
		}
	return result_len;
	}

int32_t OneChannel8BitSoundData::getData(int32_t pos, Frame& frame){
	int32_t result=0;
	if(pos<this->len){
		result=1;
		switch(channelInfo){
				case Left:
					frame.channel1=this->data[pos]*127;
					frame.channel2=0;
					break;
				case Right:
					frame.channel1=0;
					frame.channel2=this->data[pos]*127;
					break;

				case Both:
				default:
					frame.channel1=this->data[pos]*127;
					frame.channel2=frame.channel1;
					break;
			}
		}
	return result;
	}

