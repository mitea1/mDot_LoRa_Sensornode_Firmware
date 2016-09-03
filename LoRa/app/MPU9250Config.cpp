/*
 * MPU9250Config.cpp
 *
 *  Created on: 23.05.2016
 *      Author: Adrian
 */

#include "MPU9250Config.h"

MPU9250Config::MPU9250Config() {
	// TODO Auto-generated constructor stub

}

MPU9250Config::~MPU9250Config() {
	// TODO Auto-generated destructor stub
}

void MPU9250Config::build(MPU9250_MODE desiredMode){
	switch(desiredMode){
	case MPU9250_MODE_1:
		setAccelerometerScale(MPU9250_FULL_SCALE_2G);
		setGyroscopeScale(MPU9250_GYRO_FULL_SCALE_250DPS);
		setMagnetometerBitResolution(MPU9250_MAG_16_BIT);
		setMagnetometerMeasureMode(MPU9250_MAG_CONTINUOUS_MEASUREMENT_1);
		break;
	case MPU9250_MODE_2:
		setAccelerometerScale(MPU9250_FULL_SCALE_4G);
		setGyroscopeScale(MPU9250_GYRO_FULL_SCALE_500DPS);
		setMagnetometerBitResolution(MPU9250_MAG_16_BIT);
		setMagnetometerMeasureMode(MPU9250_MAG_CONTINUOUS_MEASUREMENT_1);
		break;
	case MPU9250_MODE_3:
		setAccelerometerScale(MPU9250_FULL_SCALE_8G);
		setGyroscopeScale(MPU9250_GYRO_FULL_SCALE_1000DPS);
		setMagnetometerBitResolution(MPU9250_MAG_16_BIT);
		setMagnetometerMeasureMode(MPU9250_MAG_CONTINUOUS_MEASUREMENT_1);
		break;
	case MPU9250_MODE_4:
		setAccelerometerScale(MPU9250_FULL_SCALE_2G);
		setGyroscopeScale(MPU9250_GYRO_FULL_SCALE_250DPS);
		setMagnetometerBitResolution(MPU9250_MAG_16_BIT);
		setMagnetometerMeasureMode(MPU9250_MAG_CONTINUOUS_MEASUREMENT_1);
		setInterruptPinConfiguration(MPU9250_INT_ANYRD_2CLEAR_MASK|
				MPU9250_LATCH_INT_EN_MASK);
		setWakeOnMotionThreshold(MPU9250_WOM_THRESHOLD_1020_MG);
		break;
	}
}

void MPU9250Config::setAccelerometerScale(uint8_t accelerometerScale){
	this->accelerometerScale = accelerometerScale;
}

void MPU9250Config::setGyroscopeScale(uint8_t gyroscopeScale){
	this->gyroscopeScale = gyroscopeScale;
}

void MPU9250Config::setMagnetometerBitResolution(uint8_t magnetometerBitResolution){
	this->magnetometerBitResolution = magnetometerBitResolution;
}

void MPU9250Config::setMagnetometerMeasureMode(uint8_t magnetometermeasureMode){
	this->magnetometerMeasureMode = magnetometermeasureMode;
}

void MPU9250Config::setInterruptPinConfiguration(uint8_t interruptPinConfiguration){
	this->interruptPinConfiguration = interruptPinConfiguration;
}

void MPU9250Config::setInterruptEnableConfiguration(uint8_t interruptEnbaleConfiguration){
	this->interruptEnableConfiguration = interruptEnableConfiguration;
}

void MPU9250Config::setWakeOnMotionThreshold(uint8_t wakeOnMotionThreshold){
	this->wakeOnMotionThreshold;
}

uint8_t MPU9250Config::getAccelerometerScale(){
	return accelerometerScale;
}

uint8_t MPU9250Config::getGyroscopeScale(){
	return gyroscopeScale;
}

uint8_t MPU9250Config::getMagnetometerBitResolution(){
	return magnetometerBitResolution;
}

uint8_t MPU9250Config::getMagnetometerMeasureMode(){
	return magnetometerMeasureMode;
}
float MPU9250Config::getAccelerationDivider(){
	float divider;

	switch(accelerometerScale){
		case MPU9250_FULL_SCALE_2G:
			divider = 32768/2;
			break;
		case MPU9250_FULL_SCALE_4G:
			divider = 32768/4;
			break;
		case MPU9250_FULL_SCALE_8G:
			divider = 32768/8;
			break;
		case MPU9250_FULL_SCALE_16G:
			divider = 32768/16;
			break;
		default:
			divider = 1;
			break;
	}

	return divider;
}

float MPU9250Config::getGyroDivider(){
	float divider;

	switch(accelerometerScale){
		case MPU9250_GYRO_FULL_SCALE_250DPS:
			divider = 32768/250;
			break;
		case MPU9250_GYRO_FULL_SCALE_500DPS:
			divider = 32768/500;
			break;
		case MPU9250_GYRO_FULL_SCALE_1000DPS:
			divider = 32768/1000;
			break;
		case MPU9250_GYRO_FULL_SCALE_2000DPS:
			divider = 32768/2000;
			break;
		default:
			divider = 1;
			break;
	}

	return divider;
}

float MPU9250Config::getTeslaDivider(){
	float divider;

	switch(magnetometerBitResolution){
		case MPU9250_MAG_14_BIT:
			divider = 8190/4192;
			break;
		case MPU9250_MAG_16_BIT:
			divider = 32768/4192;
			break;
		default:
			divider = 1;
			break;
	}

	return divider;
}

uint8_t MPU9250Config::getInterruptPinConfiguration(){
	return interruptPinConfiguration;
}

uint8_t MPU9250Config::getInterruptEnableConfiguration(){
	return interruptEnableConfiguration;
}

uint8_t MPU9250Config::getWakeOnMotionThreshold(){
	return wakeOnMotionThreshold;
}



