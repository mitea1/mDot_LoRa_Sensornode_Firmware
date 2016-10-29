/*
 * MPU9250AccelerationMessage.cpp
 *
 *  Created on: Jun 1, 2016
 *      Author: Adrian
 */

#include "MPU9250AccelerationMessage.h"
#include "main.h"

MPU9250AccelerationMessage::MPU9250AccelerationMessage() {
	loraMessageId.push_back(MPU9250_X_ACCELERATION_MESSAGE_ID);
	loraMessageId.push_back(MPU9250_Y_ACCELERATION_MESSAGE_ID);
	loraMessageId.push_back(MPU9250_Z_ACCELERATION_MESSAGE_ID);

}

MPU9250AccelerationMessage::~MPU9250AccelerationMessage() {
	// TODO Auto-generated destructor stub
}

void MPU9250AccelerationMessage::setXAcceleration(float xAcceleration){
	this->xAcceleration.floatValue = xAcceleration;
}

void MPU9250AccelerationMessage::setYAcceleration(float yAcceleration){
	this->yAcceleration.floatValue = yAcceleration;
}

void MPU9250AccelerationMessage::setZAcceleration(float zAcceleration){
	this->zAcceleration.floatValue = zAcceleration;
}

float MPU9250AccelerationMessage::getXAcceleration(){
	return xAcceleration.floatValue;
}

float MPU9250AccelerationMessage::getYAcceleration(){
	return yAcceleration.floatValue;
}

float MPU9250AccelerationMessage::getZAcceleration(){
	return zAcceleration.floatValue;
}

char* MPU9250AccelerationMessage::getLoRaMessageString(){

	char buffer[20];
	loraMessage.clear();
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getXAcceleration());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(1).c_str(),getYAcceleration());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(2).c_str(),getZAcceleration());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* MPU9250AccelerationMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_X_ACCELERATION_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_X_ACCELERATION_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),xAcceleration.uintValue,xAcceleration.uintValue + sizeof(xAcceleration.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Y_ACCELERATION_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Y_ACCELERATION_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),yAcceleration.uintValue,yAcceleration.uintValue + sizeof(yAcceleration.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Z_ACCELERATION_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (MPU9250_Z_ACCELERATION_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),zAcceleration.uintValue,zAcceleration.uintValue + sizeof(zAcceleration.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}



