/*
 * MPU9250.cpp
 *
 *  Created on: 19.05.2016
 *      Author: Adrian
 */

#include "MPU9250.h"

MPU9250::MPU9250(I2C_RT* i2c){
	setI2c(i2c);
	this->config = new MPU9250Config();
}

MPU9250::~MPU9250() {
	// TODO Auto-generated destructor stub
}

void MPU9250::setI2c(I2C_RT* i2c){
	this->i2c = i2c;
}

void MPU9250::init(MPU9250_MODE desiredMode){
		config->build(desiredMode);
		enableAxisAccelerationMeasurement();
		enableAxisGyroscopeMeasurement();
		enableAxisTeslaMeasurement();
		configureInterrupts();
		setWakeOnReceiveThreshold();
}

float MPU9250::getXAxisAcceleration(){
	uint8_t xAccelarationHighByte;
	uint8_t xAccelarationLowByte;

	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_ACCEL_XOUT_H,false,
			&xAccelarationHighByte,1);
	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_ACCEL_XOUT_L,false,
			&xAccelarationLowByte,1);

	int16_t acceleration = ((int16_t)xAccelarationHighByte<<8)|((int16_t)xAccelarationLowByte);

	return ((float) acceleration)/config->getAccelerationDivider();

}

float MPU9250::getYAxisAcceleration(){
	uint8_t yAccelarationHighByte;
	uint8_t yAccelarationLowByte;

	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_ACCEL_YOUT_H,false,
			&yAccelarationHighByte,1);
	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_ACCEL_YOUT_L,false,
			&yAccelarationLowByte,1);

	int16_t acceleration = yAccelarationHighByte<<8|yAccelarationLowByte;

	return ((float) acceleration)/config->getAccelerationDivider();

}

float MPU9250::getZAxisAcceleration(){
	uint8_t zAccelarationHighByte;
	uint8_t zAccelarationLowByte;

	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_ACCEL_ZOUT_H,false,
			&zAccelarationHighByte,1);
	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_ACCEL_ZOUT_L,false,
			&zAccelarationLowByte,1);

	int16_t acceleration = zAccelarationHighByte<<8|zAccelarationLowByte;

	return ((float) acceleration)/config->getAccelerationDivider();

}

float MPU9250::getXAxisGyro(){
	uint8_t xGyroscopeHighByte;
	uint8_t xGyroscopeLowByte;

	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_GYRO_XOUT_H,false,
			&xGyroscopeHighByte,1);
	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_GYRO_XOUT_L,false,
			&xGyroscopeLowByte,1);

	int16_t gyroscope = xGyroscopeHighByte<<8|xGyroscopeLowByte;

	return ((float) gyroscope)/config->getGyroDivider();
}

float MPU9250::getYAxisGyro(){
	uint8_t yGyroscopeHighByte;
	uint8_t yGyroscopeLowByte;

	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_GYRO_YOUT_H,false,
			&yGyroscopeHighByte,1);
	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_GYRO_YOUT_L,false,
			&yGyroscopeLowByte,1);

	int16_t gyroscope = yGyroscopeHighByte<<8|yGyroscopeLowByte;

	return ((float) gyroscope)/config->getGyroDivider();
}

float MPU9250::getZAxisGyro(){
	uint8_t zGyroscopeHighByte;
	uint8_t zGyroscopeLowByte;

	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_GYRO_ZOUT_H,0,
			&zGyroscopeHighByte,1);
	i2c->read_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_GYRO_ZOUT_L,0,
			&zGyroscopeLowByte,1);

	int16_t gyroscope = zGyroscopeHighByte<<8|zGyroscopeLowByte;

	return ((float) gyroscope)/config->getGyroDivider();
}

float MPU9250::getXAxisTesla(){
	uint8_t xTelsaHighByte;
	uint8_t xTelsaLowByte;

	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_XOUT_H,false,
			&xTelsaHighByte,1);
	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_XOUT_L,false,
			&xTelsaLowByte,1);

	uint8_t status;

	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_ST2,false,
			&status,1);

	int16_t tesla = xTelsaHighByte<<8|xTelsaLowByte;

	return (float) (tesla) / config->getTeslaDivider();
}

float MPU9250::getYAxisTesla(){
	uint8_t yTelsaHighByte;
	uint8_t yTelsaLowByte;

	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_YOUT_H,false,
			&yTelsaHighByte,1);
	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_YOUT_L,false,
			&yTelsaLowByte,1);

	uint8_t status;

	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_ST2,false,
			&status,1);

	int16_t tesla = yTelsaHighByte<<8|yTelsaLowByte;

	return (float) (tesla) / config->getTeslaDivider();
}

float MPU9250::getZAxisTesla(){
	uint8_t zTelsaHighByte;
	uint8_t zTelsaLowByte;

	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_ZOUT_H,false,
			&zTelsaHighByte,1);
	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_ZOUT_L,false,
			&zTelsaLowByte,1);

	uint8_t status;

	i2c->read_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_ST2,false,
			&status,1);

	int16_t tesla = zTelsaHighByte<<8|zTelsaLowByte;

	return (float) (tesla) / config->getTeslaDivider();
}

void MPU9250::enableAxisAccelerationMeasurement(){
	uint8_t configValueAcceleration=config->getAccelerometerScale()<<3;

	i2c->write_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_ACCEL_CONFIG,false,
			&configValueAcceleration,1);
}

void MPU9250::enableAxisGyroscopeMeasurement(){
	uint8_t configValueGyroscope = config->getGyroscopeScale()<<3;

	i2c->write_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_GYRO_CONFIG,false,
			&configValueGyroscope,1);
}

void MPU9250::enableAxisTeslaMeasurement(){
	uint8_t configValueMagnetometer = 0x02;

	i2c->write_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_INT_PIN_CFG,false,
			&configValueMagnetometer,1);

	configValueMagnetometer = 0;
	i2c->write_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_USER_CTRL,false,
				&configValueMagnetometer,1);

	configValueMagnetometer = 0;
	i2c->write_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_CNTL1,false,
			&configValueMagnetometer,1);

	configValueMagnetometer = config->getMagnetometerBitResolution()<<4|
			config->getMagnetometerMeasureMode();
	i2c->write_RT(MPU9250_MAG_ADDRESS,MPU9250_MAG_CNTL1,false,
			&configValueMagnetometer,1);

}

void MPU9250::configureInterrupts(){
	uint8_t configValueInterruptPin = config->getInterruptPinConfiguration()|0x02;

	i2c->write_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_INT_PIN_CFG,false,
				&configValueInterruptPin,1);

	uint8_t configValueInterruptEnable = config->getInterruptEnableConfiguration();

	i2c->write_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_INT_ENABLE,false,
				&configValueInterruptEnable,1);
}

void MPU9250::setWakeOnReceiveThreshold(){
	uint8_t wakeOnReceiveThreshold = config->getWakeOnMotionThreshold();

	i2c->write_RT(MPU9250_DEFAULT_ADDRESS,MPU9250_WOM_THR,false,
					&wakeOnReceiveThreshold,1);
}


