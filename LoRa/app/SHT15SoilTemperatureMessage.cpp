/*
 * SHT15SoilMeasurmentMessage.cpp
 *
 *  Created on: 09.01.2017
 *      Author: Adrian
 */

#include "SHT15SoilTemperatureMessage.h"
#include "main.h"

SHT15SoilTemperatureMessage::SHT15SoilTemperatureMessage() {
	loraMessageId.push_back(SHT15_SOIL_TEMPERATURE_MESSAGE_ID);

}

SHT15SoilTemperatureMessage::~SHT15SoilTemperatureMessage() {
	// TODO Auto-generated destructor stub
}

void SHT15SoilTemperatureMessage::setSoilTemperature(float soilTemperature){
	this->soilTemperature.floatValue = soilTemperature;
}

float SHT15SoilTemperatureMessage::getSoilTemperature(){
	return soilTemperature.floatValue;
}

char* SHT15SoilTemperatureMessage::getLoRaMessageString(){
	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getSoilTemperature());
	loraMessage.clear();
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* SHT15SoilTemperatureMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(),(uint8_t) (SHT15_SOIL_TEMPERATURE_BINARY_MESSAGE_ID >> 8) );
	loraMessageBinary.insert(loraMessageBinary.end(),(uint8_t) (SHT15_SOIL_TEMPERATURE_BINARY_MESSAGE_ID && 0xFF) );
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),soilTemperature.uintValue,soilTemperature.uintValue + sizeof(soilTemperature.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}



