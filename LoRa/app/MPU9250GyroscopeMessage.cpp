/*
 * MPU9250GyroscopeMessage.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "MPU9250GyroscopeMessage.h"
#include "main.h"

MPU9250GyroscopeMessage::MPU9250GyroscopeMessage() {
	loraMessageId.push_back(MPU9250_X_GYROSCOPE_MESSAGE_ID);
	loraMessageId.push_back(MPU9250_Y_GYROSCOPE_MESSAGE_ID);
	loraMessageId.push_back(MPU9250_Z_GYROSCOPE_MESSAGE_ID);
}

MPU9250GyroscopeMessage::~MPU9250GyroscopeMessage() {
	// TODO Auto-generated destructor stub
}

void MPU9250GyroscopeMessage::setXGyro(float xGyro){
	this->xGyro.floatValue = xGyro;
}

void MPU9250GyroscopeMessage::setYGyro(float yGyro){
	this->yGyro.floatValue = yGyro;
}

void MPU9250GyroscopeMessage::setZGyro(float zGyro){
	this->zGyro.floatValue = zGyro;
}

float MPU9250GyroscopeMessage::getXGyro(){
	return xGyro.floatValue;
}

float MPU9250GyroscopeMessage::getYGyro(){
	return yGyro.floatValue;
}

float MPU9250GyroscopeMessage::getZGyro(){
	return zGyro.floatValue;
}

char* MPU9250GyroscopeMessage::getLoRaMessageString(){
	loraMessage.clear();
	char buffer[20];
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getXGyro());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(1).c_str(),getYGyro());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(2).c_str(),getZGyro());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* MPU9250GyroscopeMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_X_GYROSCOPE_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_X_GYROSCOPE_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),xGyro.uintValue,xGyro.uintValue + sizeof(xGyro.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Y_GYROSCOPE_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Y_GYROSCOPE_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),yGyro.uintValue,yGyro.uintValue + sizeof(yGyro.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Z_GYROSCOPE_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Z_GYROSCOPE_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),zGyro.uintValue,zGyro.uintValue + sizeof(zGyro.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}



