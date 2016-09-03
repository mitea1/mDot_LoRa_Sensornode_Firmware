/*
 * SI1143Message.cpp
 *
 *  Created on: 02.06.2016
 *      Author: Adrian
 */

#include "SI1143ProximityMessage.h"

SI1143ProximityMessage::SI1143ProximityMessage() {
	loraMessageId.push_back(SI1143_PROXIMITY_MESSAGE_ID);

}

SI1143ProximityMessage::~SI1143ProximityMessage() {
	// TODO Auto-generated destructor stub
}

void SI1143ProximityMessage::setProximity(uint16_t proximity){
	this->proximity = proximity;
}

uint16_t SI1143ProximityMessage::getProximity(){
	return proximity;
}

char* SI1143ProximityMessage::getLoRaMessageString(){
	loraMessage.clear();
	char buffer[20];
	sprintf(buffer,"%s:%d,",loraMessageId.at(0).c_str(),getProximity());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}



