/*
 * BME280HumidityMessage.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "BME280HumidityMessage.h"
#include "main.h"

BME280HumidityMessage::BME280HumidityMessage() {
	loraMessageId.push_back(BME280_HUMIDITY_MESSAGE_ID);
}

BME280HumidityMessage::~BME280HumidityMessage() {
	// TODO Auto-generated destructor stub
}

void BME280HumidityMessage::setHumidity(float humidity){
	this->humidity.floatValue = humidity;
}

float BME280HumidityMessage::getHumidity(){
	return humidity.floatValue;
}

char* BME280HumidityMessage::getLoRaMessageString(){

	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getHumidity());
	loraMessage.clear();
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* BME280HumidityMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(),(uint8_t) (BME280_HUMIDITY_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.end(), (uint8_t) (BME280_HUMIDITY_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),humidity.uintValue,humidity.uintValue + sizeof(humidity.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}

