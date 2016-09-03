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
	this->xGyro = xGyro;
}

void MPU9250GyroscopeMessage::setYGyro(float yGyro){
	this->yGyro = yGyro;
}

void MPU9250GyroscopeMessage::setZGyro(float zGyro){
	this->zGyro = zGyro;
}

float MPU9250GyroscopeMessage::getXGyro(){
	return xGyro;
}

float MPU9250GyroscopeMessage::getYGyro(){
	return yGyro;
}

float MPU9250GyroscopeMessage::getZGyro(){
	return zGyro;
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



