/*
 * I2C_RT.cpp
 *
 *  Created on: 19.05.2016
 *      Author: Adrian
 */

#include "I2C_RT.h"

I2C_RT::I2C_RT(){

}

I2C_RT::~I2C_RT() {

}


void I2C_RT::read_RT(uint8_t address,uint16_t reg,bool isTwoBytes,uint8_t*data,uint8_t dataLenght){

	mbed::I2C i2c(I2C_SDA,I2C_SCL);
	i2c.frequency(100000);

	// Some Cast
	//TODO find a more proper solution
	int sensorAddress = (int)address;
	char dataToWrite[2] = {(char)(reg>>8),(char)reg};
	char* readData = (char*) data;

	if(isTwoBytes){
		i2c.write(sensorAddress,dataToWrite,dataLenght);
	}
	else{
		i2c.write(sensorAddress,&dataToWrite[1],dataLenght);
	}

	i2c.read(address,readData,dataLenght);

}
void I2C_RT::write_RT(uint8_t address,uint16_t reg,bool isTwoBytes,uint8_t*data,uint8_t dataLenght){
	mbed::I2C i2c(I2C_SDA,I2C_SCL);
	i2c.frequency(100000);

	// Some Cast
	//TODO find a more proper solution
	int sensorAddress = (int) address;
	char dataToWrite[3] = {(char)(reg>>8),(char)reg,(char)*data};

	if(isTwoBytes){
		i2c.write(sensorAddress,&dataToWrite[0],3);
	}
	else{
		i2c.write(sensorAddress,&dataToWrite[1],2);
	}

}

