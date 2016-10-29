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
	this->pressure.floatValue = pressure;
}

float BME280PressureMessage::getPressure(){
	return pressure.floatValue;
}

char* BME280PressureMessage::getLoRaMessageString(){

	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getPressure());
	loraMessage.clear();
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* BME280PressureMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(),(uint8_t) (BME280_PRESSURE_BINARY_MESSAGE_ID >> 8) );
	loraMessageBinary.insert(loraMessageBinary.end(),(uint8_t) (BME280_PRESSURE_BINARY_MESSAGE_ID && 0xFF) );
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),pressure.uintValue,pressure.uintValue + sizeof(pressure.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}

