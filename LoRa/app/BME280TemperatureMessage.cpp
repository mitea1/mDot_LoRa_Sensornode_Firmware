/*
 * BME280TemperatureMessage.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "BME280TemperatureMessage.h"
#include "main.h"

BME280TemperatureMessage::BME280TemperatureMessage() {
	loraMessageId.push_back(BME280_TEMPERATURE_MESSAGE_ID);
}

BME280TemperatureMessage::~BME280TemperatureMessage() {
	// TODO Auto-generated destructor stub
}

void BME280TemperatureMessage::setTemperature(float temperature){
	this->temperature.floatValue = temperature;
}

float BME280TemperatureMessage::getTemperature(){
	return temperature.floatValue;
}

char* BME280TemperatureMessage::getLoRaMessageString(){
	loraMessage.clear();
	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getTemperature());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* BME280TemperatureMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(),(uint8_t) (BME280_TEMPERATURE_BINARY_MESSAGE_ID >> 8) );
	loraMessageBinary.insert(loraMessageBinary.end(),(uint8_t) (BME280_TEMPERATURE_BINARY_MESSAGE_ID && 0xFF) );
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),temperature.uintValue,temperature.uintValue + sizeof(temperature.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}
