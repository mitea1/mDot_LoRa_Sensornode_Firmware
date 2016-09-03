/*
 * LoRaConfig.cpp
 *
 *  Created on: Jun 11, 2016
 *      Author: Adrian
 */

#include "LoRaConfig.h"

//LoRaConfig::LoRaConfig(){
//
//}
//
//LoRaConfig::~LoRaConfig(){
//
//}

void LoRaConfig::build(LORA_MODE desiredMode){

	setLORA_MODE(desiredMode);
	setNetworkName(LORA_NETWORK_NAME);
	setNetworkPassphrase(LORA_NETWORK_PASSPHRASE);
	setAppEUI();
	setAppKey();
	setDeviceEUI();

	switch(desiredMode){

		case LORA_MODE_0_OFF:
			setNetworkPublicity(true);
			setActivity(false);
			setFrequencySubBand(LORA_SUBBAND_0);
			setSpreadingFactor(LORA_SPREADING_FACTOR_7);
			setTxPowerdBm(LORA_TX_POWER_16_DBM);
			setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_1);
			setJOIN_MODE(ABP);
			break;

		case LORA_MODE_1:
			setNetworkPublicity(true);
			setActivity(true);
			setFrequencySubBand(LORA_SUBBAND_1);
			setSpreadingFactor(LORA_SPREADING_FACTOR_8);
			setTxPowerdBm(LORA_TX_POWER_16_DBM);
			setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_0);
			setJOIN_MODE(OTA);
			break;

		case LORA_MODE_2:
			setNetworkPublicity(true);
			setActivity(true);
			setFrequencySubBand(LORA_SUBBAND_0);
			setSpreadingFactor(LORA_SPREADING_FACTOR_12);
			setTxPowerdBm(LORA_TX_POWER_16_DBM);
			setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_1);
			setJOIN_MODE(ABP);
			break;

		case LORA_MODE_3:
			setNetworkPublicity(true);
			setActivity(true);
			setFrequencySubBand(LORA_SUBBAND_0);
			setSpreadingFactor(LORA_SPREADING_FACTOR_7);
			setTxPowerdBm(LORA_TX_POWER_16_DBM);
			setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_1);
			setJOIN_MODE(ABP);
			break;

		case LORA_MODE_4:
			setNetworkPublicity(true);
			setActivity(true);
			setFrequencySubBand(LORA_SUBBAND_0);
			setSpreadingFactor(LORA_SPREADING_FACTOR_7);
			setTxPowerdBm(LORA_TX_POWER_16_DBM);
			setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_1);
			setJOIN_MODE(ABP);
			break;

		case LORA_MODE_5:
			setNetworkPublicity(true);
			setActivity(true);
			setFrequencySubBand(LORA_SUBBAND_0);
			setSpreadingFactor(LORA_SPREADING_FACTOR_7);
			setTxPowerdBm(LORA_TX_POWER_20_DBM);
			setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_1);
			setJOIN_MODE(ABP);
			break;

		default:
			setNetworkPublicity(true);
			setActivity(false);
			setFrequencySubBand(LORA_SUBBAND_0);
			setSpreadingFactor(LORA_SPREADING_FACTOR_7);
			setTxPowerdBm(LORA_TX_POWER_16_DBM);
			setAcknowledgeRetries(LORA_ACKNOWLEDGE_RETRIES_1);
			setJOIN_MODE(ABP);
			break;
	}
}

bool LoRaConfig::isPublic(){
	return publicity;
}

bool LoRaConfig::isActiv(){
	return activity;
}

std::string LoRaConfig::getNetworkName(){
	return *networkName;
}

std::string LoRaConfig::getNetworkPassphrase(){
	return *networkPassphrase;
}

std::string LoRaConfig::getNetworkAddress(){
	return *networkAddress;
}

std::vector<uint8_t> LoRaConfig::getAppEUI(){
	return *appEUI;
}

std::vector<uint8_t> LoRaConfig::getAppKey(){
	return *appKey;
}

std::vector<uint8_t> LoRaConfig::getDeviceEUI(){
	return *deviceEUI;
}

uint8_t LoRaConfig::getFrequencySubBand(){
	return frequencySubBand;
}

uint8_t LoRaConfig::getSpreadingFactor(){
	return spreadingFactor;
}

uint8_t LoRaConfig::getTxPowerdBm(){
	return txPowerdBm;
}

uint8_t LoRaConfig::getAcknowledgeRetries(){
	return acknowledgeRetries;
}

LORA_MODE LoRaConfig::getLORA_MODE(){
	return loraMode;
}

JOIN_MODE LoRaConfig::getJOIN_MODE(){
	return joinMode;
}

void LoRaConfig::setNetworkPublicity(bool publicity){
	this->publicity = publicity;
}

void LoRaConfig::setActivity(bool activity){
	this->activity = activity;
}

void LoRaConfig::setNetworkName(char* networkName){
	this->networkName = new std::string(networkName);
}

void LoRaConfig::setNetworkPassphrase(char* networkPassphrase){
	this->networkPassphrase = new std::string(networkPassphrase);
}

void LoRaConfig::setNetworkAddress(char* networkAddress){
	this->networkAddress = new std::string(networkAddress);
}

void LoRaConfig::setAppEUI(){
	this->appEUI = new std::vector<uint8_t>();

	for(int i = 0; i < 8; i++){
		this->appEUI->push_back(LORA_APP_EUI[i]);
	}
}

void LoRaConfig::setAppKey(){
	this->appKey = new std::vector<uint8_t>();

	for(int i = 0; i < 16; i++){
		this->appKey->push_back(LORA_APP_KEY[i]);
	}
}

void LoRaConfig::setDeviceEUI(){
	this->deviceEUI = new std::vector<uint8_t>();

	for(int i = 0; i < 8; i++){
		this->deviceEUI->push_back(LORA_DEVICE_EUI[i]);
	}
}

void LoRaConfig::setFrequencySubBand(uint8_t frequencySubBand){
	this->frequencySubBand = frequencySubBand;
}

void LoRaConfig::setSpreadingFactor(uint8_t spreadingFactor){
	this->spreadingFactor = spreadingFactor;
}

void LoRaConfig::setTxPowerdBm(uint8_t txPowerdBm){
	this->txPowerdBm = txPowerdBm;
}

void LoRaConfig::setAcknowledgeRetries(uint8_t acknowledgeRetries){
	this->acknowledgeRetries = acknowledgeRetries;
}

void LoRaConfig::setLORA_MODE(LORA_MODE loraMode){
	this->loraMode = loraMode;
}

void LoRaConfig::setJOIN_MODE(JOIN_MODE joinMode){
	this->joinMode = joinMode;
}


