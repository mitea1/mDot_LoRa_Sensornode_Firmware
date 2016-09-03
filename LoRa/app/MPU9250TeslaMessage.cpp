/*
 * MPU9250TeslaMessage.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "MPU9250TeslaMessage.h"

MPU9250TeslaMessage::MPU9250TeslaMessage() {
	loraMessageId.push_back(MPU9250_X_TESLA_MESSAGE_ID);
	loraMessageId.push_back(MPU9250_Y_TESLA_MESSAGE_ID);
	loraMessageId.push_back(MPU9250_Z_TESLA_MESSAGE_ID);

}

MPU9250TeslaMessage::~MPU9250TeslaMessage() {

}

void MPU9250TeslaMessage::setXTesla(float xTesla){
	this->xTesla = xTesla;
}

void MPU9250TeslaMessage::setYTesla(float yTesla){
	this->yTesla = yTesla;
}

void MPU9250TeslaMessage::setZTesla(float zTesla){
	this->zTesla = zTesla;
}

float MPU9250TeslaMessage::getXTesla(){
	return xTesla;
}

float MPU9250TeslaMessage::getYTesla(){
	return yTesla;
}

float MPU9250TeslaMessage::getZTesla(){
	return zTesla;
}

char* MPU9250TeslaMessage::getLoRaMessageString(){
	loraMessage.clear();
	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getXTesla());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(1).c_str(),getYTesla());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(2).c_str(),getZTesla());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

