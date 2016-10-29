/*
 * MPU9250TeslaMessage.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "MPU9250TeslaMessage.h"
#include "main.h"

MPU9250TeslaMessage::MPU9250TeslaMessage() {
	loraMessageId.push_back(MPU9250_X_TESLA_MESSAGE_ID);
	loraMessageId.push_back(MPU9250_Y_TESLA_MESSAGE_ID);
	loraMessageId.push_back(MPU9250_Z_TESLA_MESSAGE_ID);

}

MPU9250TeslaMessage::~MPU9250TeslaMessage() {

}

void MPU9250TeslaMessage::setXTesla(float xTesla){
	this->xTesla.floatValue = xTesla;
}

void MPU9250TeslaMessage::setYTesla(float yTesla){
	this->yTesla.floatValue = yTesla;
}

void MPU9250TeslaMessage::setZTesla(float zTesla){
	this->zTesla.floatValue = zTesla;
}

float MPU9250TeslaMessage::getXTesla(){
	return xTesla.floatValue;
}

float MPU9250TeslaMessage::getYTesla(){
	return yTesla.floatValue;
}

float MPU9250TeslaMessage::getZTesla(){
	return zTesla.floatValue;
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

std::vector<uint8_t>* MPU9250TeslaMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_X_TESLA_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_X_TESLA_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),xTesla.uintValue,xTesla.uintValue + sizeof(xTesla.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Y_TESLA_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Y_TESLA_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),yTesla.uintValue,yTesla.uintValue + sizeof(yTesla.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Z_TESLA_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Z_TESLA_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),zTesla.uintValue,zTesla.uintValue + sizeof(zTesla.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}
