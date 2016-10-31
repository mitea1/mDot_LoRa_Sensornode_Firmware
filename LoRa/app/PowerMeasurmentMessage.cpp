/*
 * PowerMeasurmentMessage.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: Adrian
 */

#include "PowerMeasurmentMessage.h"
#include "main.h"

PowerMeasurementMessage::PowerMeasurementMessage() {
	loraMessageId.push_back(INA219_SHUNT_VOLTAGE_MESSAGE_ID);
	loraMessageId.push_back(INA219_BUS_VOLTAGE_MESSAGE_ID);
	loraMessageId.push_back(INA219_CURRENT_MESSAGE_ID);
	loraMessageId.push_back(INA219_POWER_MESSAGE_ID);
}

PowerMeasurementMessage::~PowerMeasurementMessage() {
	// TODO Auto-generated destructor stub
}

void PowerMeasurementMessage::setShuntVoltage(float shuntVoltage){
	this->shuntVoltage.floatValue = shuntVoltage;
}

void PowerMeasurementMessage::setBusVoltage(float busVoltage){
	this->busVoltage.floatValue = busVoltage;
}

void PowerMeasurementMessage::setCurrent(float current){
	this->current.floatValue = current;
}

void PowerMeasurementMessage::setPower(float power){
	this->power.floatValue = power;
}

float PowerMeasurementMessage::getShuntVoltage(){
	return shuntVoltage.floatValue;
}

float PowerMeasurementMessage::getBusVoltage(){
	return busVoltage.floatValue;
}

float PowerMeasurementMessage::getCurrent(){
	return current.floatValue;
}

float PowerMeasurementMessage::getPower(){
	return power.floatValue;
}

char * PowerMeasurementMessage::getLoRaMessageString(){
	char buffer[20];
	loraMessage.clear();
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(0).c_str(),getShuntVoltage());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(1).c_str(),getBusVoltage());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(2).c_str(),getCurrent());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%.2f,",loraMessageId.at(3).c_str(),getPower());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

std::vector<uint8_t>* PowerMeasurementMessage::getLoRaMessageBinary(){
	loraMessageBinary.clear();

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (INA219_SHUNT_VOLTAGE_BINARY_MESSAGE_ID>> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (INA219_SHUNT_VOLTAGE_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),shuntVoltage.uintValue,shuntVoltage.uintValue + sizeof(shuntVoltage.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (INA219_BUS_VOLTAGE_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (INA219_BUS_VOLTAGE_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),busVoltage.uintValue,busVoltage.uintValue + sizeof(busVoltage.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (INA219_CURRENT_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (INA219_CURRENT_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),current.uintValue,current.uintValue + sizeof(current.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (INA219_POWER_BINARY_MESSAGE_ID >> 8));
	loraMessageBinary.insert(loraMessageBinary.begin(), (uint8_t) (INA219_POWER_BINARY_MESSAGE_ID && 0xFF));
	loraMessageBinary.insert(loraMessageBinary.end(),0x3A);
	loraMessageBinary.insert(loraMessageBinary.end(),power.uintValue,power.uintValue + sizeof(power.floatValue));
	loraMessageBinary.insert(loraMessageBinary.end(),0x2C);

	return &(loraMessageBinary);
}

