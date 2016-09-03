/*
 * BME280PressureMessage.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "BME280PressureMessage.h"
#include "main.h"

BME280PressureMessage::BME280PressureMessage() {
	loraMessageId.push_back(BME280_PRESSURE_MESSAGE_ID);
}

BME280PressureMessage::~BME280PressureMessage() {
	// TODO Auto-generated destructor stub
}

void BME280PressureMessage::setPressure(float pressure){
	this->pressure = pressure;
}

float BME280PressureMessage::getPressure(){
	return pressure;
}

char* BME280PressureMessage::getLoRaMessageString(){

	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getPressure());
	loraMessage.clear();
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}



