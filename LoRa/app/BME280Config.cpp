/*
 * BME280Config.cpp
 *
 *  Created on: 24.05.2016
 *      Author: Adrian
 */

#include "BME280Config.h"


BME280Config::BME280Config() {
	// TODO Auto-generated constructor stub

}

BME280Config::~BME280Config() {
	// TODO Auto-generated destructor stub
}

void BME280Config::build(BME280_MODE desiredMode){
	switch(desiredMode){
	case BME280_MODE_0:
		setOversamplingTemperature(BME280_TEMP_OVRS_1);
		setOversamplingPressure(BME280_PRESS_OVRS_1);
		setOversamplingHumidity(BME280_HUM_OVRS_1);
		setMode(BME280_FORCED_MODE);
		break;
	case BME280_MODE_1:
		setOversamplingTemperature(BME280_TEMP_OVRS_1);
		setOversamplingPressure(BME280_PRESS_OVRS_1);
		setOversamplingHumidity(BME280_HUM_OVRS_1);
		setMode(BME280_NORMAL_MODE);
		break;
	case BME280_MODE_2:
		setOversamplingTemperature(BME280_TEMP_OVRS_2);
		setOversamplingPressure(BME280_PRESS_OVRS_2);
		setOversamplingHumidity(BME280_HUM_OVRS_2);
		setMode(BME280_FORCED_MODE);
		break;
	case BME280_MODE_3:
		setOversamplingTemperature(BME280_TEMP_OVRS_2);
		setOversamplingPressure(BME280_PRESS_OVRS_2);
		setOversamplingHumidity(BME280_HUM_OVRS_2);
		setMode(BME280_NORMAL_MODE);
		break;
	case BME280_MODE_4:
		setOversamplingTemperature(BME280_TEMP_OVRS_4);
		setOversamplingPressure(BME280_PRESS_OVRS_4);
		setOversamplingHumidity(BME280_HUM_OVRS_4);
		setMode(BME280_FORCED_MODE);
		break;
	case BME280_MODE_5:
		setOversamplingTemperature(BME280_TEMP_OVRS_4);
		setOversamplingPressure(BME280_PRESS_OVRS_4);
		setOversamplingHumidity(BME280_HUM_OVRS_4);
		setMode(BME280_NORMAL_MODE);
		break;
	case BME280_MODE_6:
		setOversamplingTemperature(BME280_TEMP_OVRS_8);
		setOversamplingPressure(BME280_PRESS_OVRS_8);
		setOversamplingHumidity(BME280_HUM_OVRS_8);
		setMode(BME280_FORCED_MODE);
		break;
	case BME280_MODE_7:
		setOversamplingTemperature(BME280_TEMP_OVRS_8);
		setOversamplingPressure(BME280_PRESS_OVRS_8);
		setOversamplingHumidity(BME280_HUM_OVRS_8);
		setMode(BME280_NORMAL_MODE);
		break;
	case BME280_MODE_8:
		setOversamplingTemperature(BME280_TEMP_OVRS_16);
		setOversamplingPressure(BME280_PRESS_OVRS_16);
		setOversamplingHumidity(BME280_HUM_OVRS_16);
		setMode(BME280_FORCED_MODE);
		break;
	case BME280_MODE_9:
		setOversamplingTemperature(BME280_TEMP_OVRS_16);
		setOversamplingPressure(BME280_PRESS_OVRS_16);
		setOversamplingHumidity(BME280_HUM_OVRS_16);
		setMode(BME280_NORMAL_MODE);
		break;
	default:
		setOversamplingTemperature(BME280_TEMP_OVRS_1);
		setOversamplingPressure(BME280_PRESS_OVRS_1);
		setOversamplingHumidity(BME280_HUM_OVRS_1);
		setMode(BME280_NORMAL_MODE);
		break;
	}
}

void BME280Config::setOversamplingTemperature(uint8_t oversamplingTemperature){
	this->oversamplingTemperature = oversamplingTemperature;
}

void BME280Config::setOversamplingPressure(uint8_t oversamplingPressure){
	this->oversamplingPressure = oversamplingPressure;
}

void BME280Config::setOversamplingHumidity(uint8_t oversamplingHumidity){
	this->oversamplingHumidity = oversamplingHumidity;
}

void BME280Config::setMode(uint8_t mode){
	this->mode = mode;
}

uint8_t BME280Config::getOversamplingTemperature(){
	return this->oversamplingTemperature;
}

uint8_t BME280Config::getOversamplingPressure(){
	return this->oversamplingPressure;
}

uint8_t BME280Config::getOversamplingHumidity(){
	return this->oversamplingHumidity;
}

uint8_t BME280Config::getMode(){
	return this->mode;
}

