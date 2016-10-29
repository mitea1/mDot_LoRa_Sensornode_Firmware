/*
 * MAX44009Message.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "MAX44009Message.h"
#include "main.h"

MAX44009Message::MAX44009Message() {
	this->loraMessageId.push_back(MAX44009_MESSAGE_ID);
}

MAX44009Message::~MAX44009Message() {
	// TODO Auto-generated destructor stub
}

void MAX44009Message::setLux(float lux){
	this->lux.floatValue = lux;

}

float MAX44009Message::getLux(){
	return lux.floatValue;
}

char* MAX44009Message::getLoRaMessageString(){
	loraMessage.clear();
	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getLux());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* MAX44009Message::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(),MAX44009_BINARY_MESSAGE_ID);
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),lux.uintValue,lux.uintValue + sizeof(lux.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}

