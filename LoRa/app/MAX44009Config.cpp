/*
 * MAX44009Config.cpp
 *
 *  Created on: 25.05.2016
 *      Author: Adrian
 */

#include "MAX44009Config.h"

MAX44009Config::MAX44009Config() {
	// TODO Auto-generated constructor stub

}

MAX44009Config::MAX44009Config(MAX44009_MODE desiredMode) {
	build(desiredMode);
}

MAX44009Config::~MAX44009Config() {
	// TODO Auto-generated destructor stub
}

void MAX44009Config::build(MAX44009_MODE desiredMode){
	switch(desiredMode){
		case MAX44009_MODE_0:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_800_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_OFF);
			setManualConfig(MAX_44009_MANUAL_CONFIG_OFF);
		case MAX44009_MODE_1:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_400_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			setManualConfig(MAX_44009_MANUAL_CONFIG_OFF);
			break;
		case MAX44009_MODE_2:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_200_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			setManualConfig(MAX_44009_MANUAL_CONFIG_OFF);
			break;
		case MAX44009_MODE_3:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_100_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			setManualConfig(MAX_44009_MANUAL_CONFIG_OFF);
			break;
		case MAX44009_MODE_4:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_50_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			setManualConfig(MAX_44009_MANUAL_CONFIG_ON);
			setInterruptEnable(MAX_44009_IRQ_ENABLED);
			setInterruptUpperThreshold(MAX_44009_THRESHOLD_4096_LUX);
			setInterruptLowerThreshold(0);
			break;
		case MAX44009_MODE_5:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_25_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			setManualConfig(MAX_44009_MANUAL_CONFIG_ON);
			break;
		case MAX44009_MODE_6:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_12_5_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
			setManualConfig(MAX_44009_MANUAL_CONFIG_ON);
			break;
		default:
			setIntegrationTime(MAX_44009_INTEGRATION_TIME_800_MS);
			setContinousMode(MAX_44009_CONTINOUS_MODE_ON);
		}
}

uint8_t MAX44009Config::getIntegrationTime(){
	return this->integrationTime;
}

uint8_t MAX44009Config::getContinousMode(){
	return this->continousMode;
}

uint8_t MAX44009Config::getInterruptEnable(){
	return this->interruptEnable;
}

uint8_t MAX44009Config::getUpperThreshold(){
	return this->upperThreshold;
}

uint8_t MAX44009Config::getLowerThreshold(){
	return this->lowerThreshold;
}

void MAX44009Config::setIntegrationTime(uint8_t integrationTime){
	this->integrationTime = integrationTime;
}

void MAX44009Config::setContinousMode(uint8_t continousMode){
	this->continousMode = continousMode;
}

void MAX44009Config::setManualConfig(uint8_t manualConfig){
	this->manualConfig = manualConfig;
}

void MAX44009Config::setInterruptEnable(uint8_t interruptEnable){
	this->interruptEnable = interruptEnable;
}

void MAX44009Config::setInterruptUpperThreshold(uint8_t upperThreshold){
	this->upperThreshold = upperThreshold;
}

void MAX44009Config::setInterruptLowerThreshold(uint8_t lowerThreshold){
	this->lowerThreshold = lowerThreshold;
}
