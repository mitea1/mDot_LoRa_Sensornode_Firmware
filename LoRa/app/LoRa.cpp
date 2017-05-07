/*
 * LoRa.cpp
 *
 *  Created on: May 31, 2016
 *      Author: Adrian
 */

#include "LoRa.h"

LoRa::LoRa(mDot* dot,RawSerial* debugSerial) {
	this->dot = dot;
	this->debugSerial = debugSerial;
	this->config = new LoRaConfig();
	this->dot->setActivityLedPin(PA_0);
	this->dot->setActivityLedEnable(true);
}

LoRa::~LoRa() {
	// TODO Auto-generated destructor stub
}

void LoRa::init(LORA_MODE desiredMode){
	config->build(desiredMode);

	resetConfig();

    setNetworkName();
	setNetworkPassphrase();
	setAppEUI();
	setAppKey();
	setFrequencySubBand();
	setPublicNetwork();
	setSpreadingFactor();
    setAckRetries();
    setTxPower();
    setJoinMode();

    saveConfig();

    if(config->isActiv()){
    	joinNetwork();
    }

}

int32_t LoRa::setPublicNetwork(){
	int32_t ret;
	bool publicity = config->isPublic();

	if ((ret = dot->setPublicNetwork(publicity)) != mDot::MDOT_OK) {
	        debugSerial->printf("failed to set public network %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setFrequencySubBand(){
	int32_t ret;
	uint8_t subBand = config->getFrequencySubBand();

	debugSerial->printf("setting frequency sub band: %d \n",subBand);

	if ((ret = dot->setFrequencySubBand(subBand)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set frequency sub band %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setNetworkName(){
	int32_t ret;
	std::string networkName = config->getNetworkName();

	debugSerial->printf("setting network name:%s\n",networkName.c_str());

	if ((ret = dot->setNetworkName(networkName)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set network name %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setNetworkPassphrase(){
	int32_t ret;
	std::string networkPassphrase = config->getNetworkPassphrase();
	debugSerial->printf("setting network password: %s\n",networkPassphrase.c_str());

	if ((ret = dot->setNetworkPassphrase(networkPassphrase)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set network password %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setAppEUI(){
	int32_t ret;
	std::vector<uint8_t> appEUI = config->getAppEUI();

	debugSerial->printf("setting App EUI\n");

	if ((ret = dot->setNetworkId(appEUI)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set App EUI %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;

}

int32_t LoRa::setAppKey(){
	int32_t ret;
	std::vector<uint8_t> appKey = config->getAppKey();

	debugSerial->printf("setting App Key\n");

	if ((ret = dot->setNetworkKey(appKey)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set App Key %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}



int32_t LoRa::setJoinMode(){
	int32_t ret;
	JOIN_MODE joinMode = config->getJOIN_MODE();

	debugSerial->printf("setting join mode\n");

	if(joinMode == OTA){
		if ((ret = dot->setJoinMode(mDot::OTA)) != mDot::MDOT_OK) {
			debugSerial->printf("failed to set network address %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
		}
	}
	else if(joinMode == ABP){
		if ((ret = dot->setJoinMode(mDot::MANUAL)) != mDot::MDOT_OK) {
			debugSerial->printf("failed to set network address %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
		}
	}

	return ret;
}

int32_t LoRa::setSpreadingFactor(){
	int32_t ret;

	spreadingFactor = config->getSpreadingFactor();
	mDot::DataRates spreadingFactorMdot;

	switch(spreadingFactor){
		case LORA_SPREADING_FACTOR_7:
			spreadingFactorMdot = mDot::SF_7;
			break;

		case LORA_SPREADING_FACTOR_8:
			spreadingFactorMdot = mDot::SF_8;
			break;

		case LORA_SPREADING_FACTOR_9:
			spreadingFactorMdot = mDot::SF_9;
			break;

		case LORA_SPREADING_FACTOR_10:
			spreadingFactorMdot = mDot::SF_10;
			break;

		case LORA_SPREADING_FACTOR_11:
			spreadingFactorMdot = mDot::SF_11;
			break;

		case LORA_SPREADING_FACTOR_12:
			spreadingFactorMdot = mDot::SF_12;
			break;

		default:
			spreadingFactorMdot = mDot::SF_12;
			break;
	}

	debugSerial->printf("setting TX spreading factor\n");
	if ((ret = dot->setTxDataRate(spreadingFactorMdot)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to set TX datarate %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

int32_t LoRa::setTxPower(){
	txPowerdBm = config->getTxPowerdBm();
	dot->setTxPower(txPowerdBm);
}

int32_t LoRa::setAckRetries(){
	int32_t ret;
	uint8_t retries = config->getAcknowledgeRetries();

	debugSerial->printf("enabling ACKs\n");
	if ((ret = dot->setAck(retries)) != mDot::MDOT_OK) {
		debugSerial->printf("failed to enable ACKs %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
	}

	return ret;
}

void LoRa::resetConfig(){
	dot->resetConfig();
}

void LoRa::saveConfig(){
	debugSerial->printf("saving config\n");
	if (! dot->saveConfig()) {
		debugSerial->printf("failed to save configuration\n");
	}
}


int32_t LoRa::send(std::vector<uint8_t>& data){
	int32_t ret = mDot::MDOT_NOT_JOINED;

	if(config->isActiv()){
		ret=dot->send(data);
		if (ret != mDot::MDOT_OK) {
			debugSerial->printf("failed to send\n");
			debugSerial->printf(mDot::getReturnCodeString(ret).c_str());
			debugSerial->printf("\n");
		} else {
			debugSerial->printf("successfully sent data to gateway\n");
		}
	}

		return ret;
}

int32_t LoRa::recv(std::vector<uint8_t>& data){
	int32_t ret = mDot::MDOT_NOT_JOINED;
	if(config->isActiv()){
		ret = dot->recv(data);
	}
	return ret;
}

int16_t LoRa::getLastRssi(){
	return dot->getRssiStats().last;
}

int16_t LoRa::getLastSnr(){
	return snr;
}

uint8_t LoRa::getSpreadingFactor(){
	return spreadingFactor;
}

uint8_t LoRa::getTxPowerdBm(){
	return txPowerdBm;
}

void LoRa::ping(){
	mDot::ping_response response = dot->ping();
}

uint32_t LoRa::getNextTxMs(){
	return dot->getNextTxMs();
}


void LoRa::joinNetwork(){
	int32_t ret;
    // attempt to join the network
    debugSerial->printf("joining network\n");
    while ((ret = dot->joinNetwork()) != mDot::MDOT_OK) {
        debugSerial->printf("failed to join network %d:%s\n", ret, mDot::getReturnCodeString(ret).c_str());
        // in the 868 (EU) frequency band, we need to wait until another channel is available before transmitting again
        osDelay(std::max((uint32_t)1000, (uint32_t)dot->getNextTxMs()));
    }
    debugSerial->printf("Network joined\n");
}

