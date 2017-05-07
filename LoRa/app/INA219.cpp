/*
 * INA219.cpp
 *
 *  Created on: Oct 29, 2016
 *      Author: Adrian
 */

#include "INA219.h"

INA219::INA219(I2C_RT* i2c) {
	this->setI2C(i2c);
}

INA219::~INA219() {
	// TODO Auto-generated destructor stub
}

void INA219::init(INA219_MODE desiredMode){
	config->build(desiredMode);
	//Define more specific Settings in the future
	setCalibration_16V_400mA();
}

void INA219::setI2C(I2C_RT* i2c){
	this->i2c = i2c;
}

void INA219::setCalibration_32V_2A(void){
	this->ina219_calValue = 4096;
	this->ina219_currentDivider_mA = 10;
	this->ina219_powerDivider_mW = 2;

	uint8_t calValue[2] = {(uint8_t) (ina219_calValue >> 8), (uint8_t) (ina219_calValue)};

	i2c->write_RT(INA219_ADDRESS,INA219_REG_CALIBRATION,false,calValue,2);

	uint16_t config = 	INA219_CONFIG_BVOLTAGERANGE_32V |
            			INA219_CONFIG_GAIN_8_320MV |
            			INA219_CONFIG_BADCRES_12BIT |
            			INA219_CONFIG_SADCRES_12BIT_1S_532US |
            			INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

	uint8_t confValue[2] = {(uint8_t) (config >> 8),(uint8_t) (config)};

	i2c->write_RT(INA219_ADDRESS,INA219_REG_CONFIG,false,confValue,2);
}

void INA219::setCalibration_32V_1A(void){
	this->ina219_calValue = 10240;
	this->ina219_currentDivider_mA = 25;
	this->ina219_powerDivider_mW = 1;

	uint8_t calValue[2] = {(uint8_t) (ina219_calValue >> 8), (uint8_t) (ina219_calValue)};

	i2c->write_RT(INA219_ADDRESS,INA219_REG_CALIBRATION,false,calValue,2);

	uint16_t config = 	INA219_CONFIG_BVOLTAGERANGE_32V |
						INA219_CONFIG_GAIN_8_320MV |
						INA219_CONFIG_BADCRES_12BIT |
						INA219_CONFIG_SADCRES_12BIT_1S_532US |
						INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

	uint8_t confValue[2] = {(uint8_t) (config >> 8),(uint8_t) (config)};

	i2c->write_RT(INA219_ADDRESS,INA219_REG_CONFIG,false,confValue,2);
}

void INA219::setCalibration_16V_400mA(void){
	this->ina219_calValue = 8192;
	this->ina219_currentDivider_mA = 20;
	this->ina219_powerDivider_mW = 1;

	uint8_t calValue[2] = {(uint8_t) (ina219_calValue >> 8), (uint8_t) (ina219_calValue)};

	i2c->write_RT(INA219_ADDRESS,INA219_REG_CALIBRATION,false,calValue,2);

	uint16_t config = 	INA219_CONFIG_BVOLTAGERANGE_16V |
						INA219_CONFIG_GAIN_1_40MV |
						INA219_CONFIG_BADCRES_12BIT |
						INA219_CONFIG_SADCRES_12BIT_1S_532US |
						INA219_CONFIG_MODE_SANDBVOLT_CONTINUOUS;

	uint8_t confValue[2] = {(uint8_t) (config >> 8),(uint8_t) (config)};

	i2c->write_RT(INA219_ADDRESS,INA219_REG_CONFIG,false,confValue,2);
}

int16_t INA219::getBusVoltage_raw(void){
	uint8_t rawVoltage[2];

	i2c->read_RT(INA219_ADDRESS,INA219_REG_BUSVOLTAGE,false,rawVoltage,2);

	uint16_t rawVoltage_16 = (rawVoltage[0] << 8) | rawVoltage[1];

	return (int16_t) ((rawVoltage_16 >> 3)) * 4 ;
}

int16_t INA219::getShuntVoltage_raw(void){
	uint8_t rawVoltage[2];

	i2c->read_RT(INA219_ADDRESS,INA219_REG_SHUNTVOLTAGE,false,rawVoltage,2);

	uint16_t rawVoltage_16 = (rawVoltage[0] << 8 )|rawVoltage[1];

	int16_t voltage = (int16_t) rawVoltage_16;

	return voltage;

}

int16_t INA219::getCurrent_raw(void){
	uint8_t rawCurrent[2] ;

	i2c->read_RT(INA219_ADDRESS,INA219_REG_CURRENT,false,rawCurrent,2);

	uint16_t rawCurrent_16 = (rawCurrent[0] << 8) | rawCurrent[1] ;

	return (int16_t) rawCurrent_16;

}

int16_t INA219::getPower_raw(void){
	uint8_t rawPower[2] ;

	i2c->read_RT(INA219_ADDRESS,INA219_REG_POWER,false,rawPower,2);

	uint16_t rawPower_16 = (rawPower[0] << 8) | rawPower[1] ;

	return (int16_t) rawPower_16;
}

float INA219::getShuntVoltage_mV(){
	int16_t shuntVoltage = getShuntVoltage_raw();

	return ((float) shuntVoltage) * 0.01;
}

float INA219::getBusVoltage_V(){
	int16_t value = getBusVoltage_raw();

	return ((float) value) * 0.001;
}

float INA219::getCurrent_mA(){
	int16_t value = getCurrent_raw();

	return ((float) value)/ina219_currentDivider_mA;

}

float INA219::getPower_mW(){
	int16_t value = getPower_raw();

	return ((float) value)/ina219_powerDivider_mW;
}

