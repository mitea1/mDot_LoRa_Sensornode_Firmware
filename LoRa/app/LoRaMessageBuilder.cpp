/*
 * LoRaMessageBuilder.cpp
 *
 *  Created on: 15.12.2016
 *      Author: Adrian
 */

#include "LoRaMessageBuilder.h"

LoRaMessageBuilder::LoRaMessageBuilder() {
	this->messageAscii = new std::string();
	this->messageByte = new std::vector<uint8_t>();
	this->messageReceive = new std::vector<uint8_t>();


}

LoRaMessageBuilder::~LoRaMessageBuilder() {

}

void LoRaMessageBuilder::appendLoRaMessage(void* messageToAppend){
	this->sensorMessage = (SensorMessage*) messageToAppend;
	messageAscii->append(sensorMessage->getLoRaMessageString());
	messageByte->insert(messageByte->end(),
			sensorMessage->getLoRaMessageBinary()->begin(),sensorMessage->getLoRaMessageBinary()->end());
}

std::string* LoRaMessageBuilder::getMessageAscii(){
	return this->messageAscii;
}

SensorMessage* LoRaMessageBuilder::getSensorMessage(){
	return this->sensorMessage;
}


