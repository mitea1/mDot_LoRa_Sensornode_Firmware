/*
 * LoRaMeasuermentMessage.cpp
 *
 *  Created on: 13.06.2016
 *      Author: Adrian
 */

#include "LoRaMeasuermentMessage.h"
#include "main.h"

LoRaMeasurementMessage::LoRaMeasurementMessage() {
	loraMessageId.push_back(LORA_MEASURMENT_RSSI_MESSAGE_ID);
	loraMessageId.push_back(LORA_MEASURMENT_SNR_MESSAGE_ID);
	loraMessageId.push_back(LORA_MEASURMENT_SPREADING_FACTOR_MESSAGE_ID);
	loraMessageId.push_back(LORA_MEASURMENT_TX_POWER_MESSAGE_ID);

}

LoRaMeasurementMessage::~LoRaMeasurementMessage() {

}

void LoRaMeasurementMessage::setRssi(int16_t rssi){
	this->rssi = rssi;
}

int16_t LoRaMeasurementMessage::getRssi(){
	return rssi;
}

void LoRaMeasurementMessage::setSnr(int16_t snr){
	this->snr = snr;
}

int16_t LoRaMeasurementMessage::getSnr(){
	return snr;
}

void LoRaMeasurementMessage::setSpreadingFactor(uint8_t spreadingFactor){
	this->spreadingFactor = spreadingFactor;
}

uint8_t LoRaMeasurementMessage::getSpreadingFactor(){
	return spreadingFactor;
}

void LoRaMeasurementMessage::setTxPowerdBm(uint8_t txPowerdBm){
	this->txPowerdBm = txPowerdBm;
}

uint8_t LoRaMeasurementMessage::getTxPowerdBm(){
	return txPowerdBm;
}

char* LoRaMeasurementMessage::getLoRaMessageString(){
	char buffer[20];
	loraMessage.clear();
	sprintf(buffer,"%s:%d,",loraMessageId.at(0).c_str(),getRssi());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%d,",loraMessageId.at(1).c_str(),getSnr());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%d,",loraMessageId.at(2).c_str(),getSpreadingFactor());
	loraMessage.append(buffer);
	sprintf(buffer,"%s:%d,",loraMessageId.at(3).c_str(),getTxPowerdBm());
	loraMessage.append(buffer);
	return (char*) loraMessage.c_str();
}

