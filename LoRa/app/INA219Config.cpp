/*
 * INA219Config.cpp
 *
 *  Created on: 01.11.2016
 *      Author: Adrian
 */

#include "INA219Config.h"

INA219Config::INA219Config() {
	// TODO Auto-generated constructor stub

}

INA219Config::~INA219Config() {
	// TODO Auto-generated destructor stub
}

void INA219Config::build(INA219_MODE desiredMode){
	switch(desiredMode){
	case INA219_MODE_0:
		break;
	case INA219_MODE_1:
		break;
	case INA219_MODE_2:
		break;
	}
}

void INA219Config::setMode(uint8_t mode){
	this->mode = mode;
}

uint8_t INA219Config::getMode(){
	return this->mode;
}

