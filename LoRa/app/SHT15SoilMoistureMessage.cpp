/*
 * SHT15SoilMoistureMessage.cpp
 *
 *  Created on: 09.01.2017
 *      Author: Adrian
 */

#include "SHT15SoilMoistureMessage.h"
#include "main.h"

SHT15SoilMoistureMessage::SHT15SoilMoistureMessage() {
	loraMessageId.push_back(SHT15_SOIL_MOISTURE_MESSAGE_ID);

}

SHT15SoilMoistureMessage::~SHT15SoilMoistureMessage() {
	// TODO Auto-generated destructor stub
}

void SHT15SoilMoistureMessage::setSoilMoisture(float soilMoisture){
	this->soilMoisture.floatValue = soilMoisture;
}

float SHT15SoilMoistureMessage::getSoilMoisture(){
	return soilMoisture.floatValue;
}

char* SHT15SoilMoistureMessage::getLoRaMessageString(){
	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getSoilMoisture());
	loraMessage.clear();
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* SHT15SoilMoistureMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(),(uint8_t) (SHT15_SOIL_MOISTURE_BINARY_MESSAGE_ID >> 8) );
	loraMessageBinary.insert(loraMessageBinary.end(),(uint8_t) (SHT15_SOIL_MOISTURE_BINARY_MESSAGE_ID && 0xFF) );
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),soilMoisture.uintValue,soilMoisture.uintValue + sizeof(soilMoisture.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}

