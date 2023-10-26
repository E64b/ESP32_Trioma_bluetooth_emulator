#include "main.h"

J1850VPW vpw;
UIState uiState;
BluetoothA2DPSink a2dp;

void setup(){
	Serial.begin(115200);
	while(!Serial){
		}
	Serial.println("Serial OK");

	pinMode(LED_BUILTIN, OUTPUT);

	static i2s_config_t CONFIG={
		.mode=(i2s_mode_t)(I2S_MODE_MASTER|I2S_MODE_TX|I2S_MODE_DAC_BUILT_IN),
		.sample_rate=44100,
		.channel_format=I2S_CHANNEL_FMT_RIGHT_LEFT,
		.communication_format=(i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
		.bits_per_sample=(i2s_bits_per_sample_t)16,
		.intr_alloc_flags=0,
		.dma_buf_len=64,
		.dma_buf_count=8,
		.use_apll=false
		};

	a2dp.set_i2s_config(CONFIG);
	a2dp.start("E64b_A2DP_JR41");
	a2dp.set_volume(uiState.Vol);

	uiState.Pong=false;
	vpw.init(RX, TX);
	}


void loop(){
	readJ1850Messages();
	EmulatedKeys();
	//ChangerActivate();
	bt_music();
	}