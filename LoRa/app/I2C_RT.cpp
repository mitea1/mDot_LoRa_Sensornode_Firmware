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
		i2c.write(sensorAddress,dataToWrite,2);
	}
	else{
		i2c.write(sensorAddress,&dataToWrite[1],1);
	}

	i2c.read(address,readData,dataLenght);



}
void I2C_RT::write_RT(uint8_t address,uint16_t reg,bool isTwoBytes,uint8_t*data,uint8_t dataLenght){
	mbed::I2C i2c(I2C_SDA,I2C_SCL);
	i2c.frequency(100000);

	// Some Cast
	//TODO find a more proper solution
	int sensorAddress = (int)address;
	int i;
	char data_Char[dataLenght];


	if(isTwoBytes){
		char registerToWrite[2] = {(char)(reg>>8),(char)reg};
		char dataToWrite[(2 + dataLenght)];

		dataToWrite[0] = registerToWrite[0];
		dataToWrite[1] = registerToWrite[1];

		for( i = 0 ; i < (2 + dataLenght) ; i++){
			dataToWrite[i+2] = data[i];
		}


		i2c.write(sensorAddress,dataToWrite,2 + dataLenght);
	}
	else{
		char registerToWrite[1] = {(char)reg};
		char dataToWrite[(1 + dataLenght)];
		dataToWrite[0] = registerToWrite[0];

		for( i = 0 ; i < (2 + dataLenght) ; i++){
			dataToWrite[i+1] = data[i];
		}

		i2c.write(sensorAddress,dataToWrite,1 + dataLenght);
	}



}

