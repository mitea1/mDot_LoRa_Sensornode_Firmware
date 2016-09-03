/*
 * uBlox.cpp
 *
 *  Created on: 16.05.2016
 *      Author: Adrian
 */

#include "uBlox.h"

uBlox::uBlox(mbed::RawSerial* serial) {
	decoder = new Decoder(serial);
	this->serial = serial;
	this->config = new uBloxConfig();
}

uBlox::~uBlox() {
	delete decoder;
}

unsigned long uBlox::getTimeOfWeekMs(){
	return decoder->getLastPoslhh().iTOW;
}

float uBlox::getLongitude(){
	return (float) (decoder->getLastPoslhh().lon) / 10000000;
}

float uBlox::getLatitude(){
	return (float) (decoder->getLastPoslhh().lat) / 10000000;
}

signed long uBlox::getHeightAboveEllipsoid(){
	return decoder->getLastPoslhh().height;
}

signed long uBlox::getHeightAboveMeanSeaLevel(){
	return decoder->getLastPoslhh().hMSL;
}

unsigned long uBlox::getHorizontalAccuracyEstimate(){
	return decoder->getLastPoslhh().hAcc;
}

unsigned long uBlox::getVerticalAccuracyEstimate(){
	return decoder->getLastPoslhh().vAcc;
}

void uBlox::init(uBLOX_MODE desiredMode){
	config->build(desiredMode);
	std::vector< std::vector<uint8_t> > initialConfigurationStrings = config->getInitialConfigurationString();

	for(uint8_t i = 0 ; i < initialConfigurationStrings.size() ; i++){
		sendConfigurationString( initialConfigurationStrings.at(i) );
	}

}

void uBlox::sendConfigurationString(std::vector<uint8_t> commandString){
	for(uint8_t i = 0 ; i < commandString.size() ; i++){
		uint8_t character = commandString.at(i);
		serial->putc(character);
	}

	osDelay(100);
}




