/*
 * UBloxGPSMessage.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "UBloxGPSMessage.h"
#include "main.h"

UBloxGPSMessage::UBloxGPSMessage() {
	loraMessageId.push_back(UBLOX_GPS_MESSAGE_ITOW_ID);
	loraMessageId.push_back(UBLOX_GPS_MESSAGE_LONGITUDE_ID);
	loraMessageId.push_back(UBLOX_GPS_MESSAGE_LATITUDE_ID);
	loraMessageId.push_back(UBLOX_GPS_MESSAGE_HEIGHT_ID);
	loraMessageId.push_back(UBLOX_GPS_MESSAGE_HMSL_ID);
	loraMessageId.push_back(UBLOX_GPS_MESSAGE_HACC_ID);
	loraMessageId.push_back(UBLOX_GPS_MESSAGE_VACC_ID);
}

UBloxGPSMessage::~UBloxGPSMessage() {

}

void UBloxGPSMessage::setLongitude(float longitude){
	this->longitude = longitude;
}

void UBloxGPSMessage::setLatitude(float latitude){
	this->latitude = latitude;
}

float UBloxGPSMessage::getLongitude(){
	return longitude;
}

float UBloxGPSMessage::getLatitude(){
	return latitude;
}

char* UBloxGPSMessage::getLoRaMessageString(){

	char buffer[20];
	loraMessage.clear();
	sprintf(buffer,"%s:%.8f,",loraMessageId.at(1).c_str(),getLongitude());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.8f,",loraMessageId.at(2).c_str(),getLatitude());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}


