/*
 * SI1143Config.cpp
 *
 *  Created on: 02.06.2016
 *      Author: Adrian
 */

#include "SI1143Config.h"

SI1143Config::SI1143Config() {
	// TODO Auto-generated constructor stub

}

SI1143Config::~SI1143Config() {
	// TODO Auto-generated destructor stub
}

void SI1143Config::build(SI1143_MODE desiredMode){
	switch(desiredMode){
	case SI1143_MODE_1:
		setLed1Voltage(SI1143_LED_VOLTAGE_50_MV);
		break;
	case SI1143_MODE_2:
		setLed1Voltage(SI1143_LED_VOLTAGE_185_MV);
		break;
	case SI1143_MODE_3:
		setLed1Voltage(SI1143_LED_VOLTAGE_410_MV);
		break;
	case SI1143_MODE_4:
		setLed1Voltage(SI1143_LED_VOLTAGE_410_MV);
		setInterruptEnable(SI1143_PS1_IRQ_EN_MASK);
		setProximitySensing1Threshold(SI1143_THRESHOLD_1000);
		break;

	}
}

uint8_t SI1143Config::getLed1Voltage(){
	return led1Voltage;
}

uint8_t SI1143Config::getProximitySensing1Threshold(){
	return proximitySensing1Threshold;
}

uint8_t SI1143Config::getInterruptEnable(){
	return interruptEnable;
}

void SI1143Config::setLed1Voltage(uint8_t ledVoltage){
	this->led1Voltage = ledVoltage;
}

void SI1143Config::setInterruptEnable(uint8_t interruptEnable){
	this->interruptEnable = interruptEnable;
}

void SI1143Config::setProximitySensing1Threshold(uint16_t threshold){
	this->proximitySensing1Threshold = threshold;
}




