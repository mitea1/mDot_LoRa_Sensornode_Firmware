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
	this->lux = lux;

}

float MAX44009Message::getLux(){
	return lux;
}

char* MAX44009Message::getLoRaMessageString(){
	loraMessage.clear();
	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getLux());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

