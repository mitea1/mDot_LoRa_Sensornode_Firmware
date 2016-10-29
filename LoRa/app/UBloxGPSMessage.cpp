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
	this->longitude.floatValue = longitude;
}

void UBloxGPSMessage::setLatitude(float latitude){
	this->latitude.floatValue = latitude;
}

float UBloxGPSMessage::getLongitude(){
	return longitude.floatValue;
}

float UBloxGPSMessage::getLatitude(){
	return latitude.floatValue;
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

std::vector<uint8_t>* UBloxGPSMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(),(uint8_t) (UBLOX_GPS_BINARY_MESSAGE_LONGITUDE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.end(), (uint8_t) (UBLOX_GPS_BINARY_MESSAGE_LONGITUDE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),longitude.uintValue,longitude.uintValue + sizeof(longitude.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(),(uint8_t) (UBLOX_GPS_BINARY_MESSAGE_LATITUDE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.end(), (uint8_t) (UBLOX_GPS_BINARY_MESSAGE_LATITUDE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),latitude.uintValue,latitude.uintValue + sizeof(latitude.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}


