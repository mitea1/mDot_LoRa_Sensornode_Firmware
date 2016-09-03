/*
 * uBloxConfig.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "uBloxConfig.h"

uBloxConfig::uBloxConfig() {
	uint8_t commandArray_1 [16] = {0xB5,0x62,0x06,0x57,0x08,0x00,0x01,0x00,0x00,0x00,0x20,0x4E,0x55,0x52,0x7B,0xC3};
	connectCommandAndString(UBLOX_GNSS_ON,commandArray_1,16);

	uint8_t commandArray_2 [16] = {0xB5,0x62,0x06,0x57,0x08,0x00,0x01,0x00,0x00,0x00,0x50,0x4F,0x54,0x53,0xAC,0x85};
	connectCommandAndString(UBLOX_GNSS_OFF,commandArray_2,16);

	uint8_t commandArray_3 [10] = {0xB5,0x62,0x06,0x11,0x02,0x00,0x08,0x00,0x21,0x91};
	connectCommandAndString(UBLOX_CONTINUOUS_MODE,commandArray_3,10);

	uint8_t commandArray_4 [10] = {0xB5,0x62,0x06,0x11,0x02,0x00,0x08,0x01,0x22,0x92};
	connectCommandAndString(UBLOX_POWER_SAVE_MODE,commandArray_4,10);

	uint8_t commandArray_5 [10] = {0xB5,0x62,0x06,0x11,0x02,0x00,0x08,0x04,0x25,0x95};
	connectCommandAndString(UBLOX_ECO_MODE,commandArray_5,10);

	uint8_t commandArray_6 [28] = {0xB5,0x62,0x06,0x00,0x14,0x00,0x01,0x00,0x00,0x00,0xD0,0x08,0x00,0x00,0x80,
			0x25,0x00,0x00,0x01,0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x9A,0x79};
	connectCommandAndString(UBLOX_DISABLE_ALL_STRING,commandArray_6,28);

	uint8_t commandArray_7 [16] = {0xB5,0x62,0x06,0x01,0x08,0x00,0x01,0x02,0x00,0x01,0x00,0x00,0x00,0x00,0x13,0xBE};
	connectCommandAndString(UBLOX_ENABLE_POSLLH_STRING,commandArray_7,16);

}

uBloxConfig::~uBloxConfig() {
	// TODO Auto-generated destructor stub
}

void uBloxConfig::build(uBLOX_MODE desiredMode){
	switch(desiredMode){

	case uBLOX_MODE_0:
		initialCommands.push_back(configCommands[UBLOX_DISABLE_ALL_STRING]);
		initialCommands.push_back(configCommands[UBLOX_ENABLE_POSLLH_STRING]);
		initialCommands.push_back(configCommands[UBLOX_ECO_MODE]);
		initialCommands.push_back(configCommands[UBLOX_GNSS_ON]);
		break;

	case uBLOX_MODE_1:
		initialCommands.push_back(configCommands[UBLOX_DISABLE_ALL_STRING]);
		initialCommands.push_back(configCommands[UBLOX_ENABLE_POSLLH_STRING]);
		initialCommands.push_back(configCommands[UBLOX_CONTINUOUS_MODE]);
		initialCommands.push_back(configCommands[UBLOX_GNSS_ON]);
		break;

	case uBLOX_MODE_2:
		initialCommands.push_back(configCommands[UBLOX_DISABLE_ALL_STRING]);
		initialCommands.push_back(configCommands[UBLOX_ENABLE_POSLLH_STRING]);
		initialCommands.push_back(configCommands[UBLOX_POWER_SAVE_MODE]);
		initialCommands.push_back(configCommands[UBLOX_GNSS_ON]);
		break;

	case uBLOX_MODE_3:
		initialCommands.push_back(configCommands[UBLOX_DISABLE_ALL_STRING]);
		initialCommands.push_back(configCommands[UBLOX_GNSS_OFF]);
		break;

	}


}

std::vector< std::vector<uint8_t> > uBloxConfig::getInitialConfigurationString(){
	return initialCommands;
}

void uBloxConfig::connectCommandAndString(std::string command, uint8_t* string, uint8_t stringSize){
	std::vector <uint8_t> commandVector(string, string + stringSize);
	configCommands[command] = commandVector;
}

