/*
 * SI1143.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: Adrian
 */

#include "SI1143.h"

SI1143::SI1143(I2C_RT* i2c)
{
    this->i2c = i2c;
    this->config = new SI1143Config();
}

void SI1143::init(SI1143_MODE desiredMode){
	config->build(desiredMode);
	restart();
}

void SI1143::restart()
{
    command(SI1143_RESET);
    osDelay(30);
    uint8_t writeValue;

    // Setting up LED Power to full
    writeValue = SI1143_HW_KEY_VAL0;
    i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_HW_KEY,false,&writeValue,1);
    writeValue = config->getLed1Voltage();
    i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_PS_LED21,false,&writeValue,1);
    writeValue = 0x0A;
    i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_PS_LED3,false,&writeValue,1);
    writeValue = SI1143_ALS_IR_TASK + SI1143_ALS_VIS_TASK + SI1143_PS1_TASK +
    		SI1143_PS2_TASK + SI1143_PS3_TASK;
    i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_PARAM_WR,false,&writeValue,1);
    command(SI1143_PARAM_SET + (SI1143_CHLIST & 0x1F));
    writeValue = 0x04;
	i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_PARAM_WR,false,&writeValue,1);
    command(SI1143_PARAM_SET + (SI1143_PS_ADC_MISC & 0x1F));

    i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_INT_CFG,false,0,1);
    i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_IRQ_ENABLE,false,0,1);
    i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_IRQ_MODE1,false,0,1);
    i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_IRQ_MODE2,false,0,1);
}
//
void SI1143::command(uint8_t cmd)
{
    uint8_t val;

    i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_RESPONSE,false,&val,1);
    osDelay(100);
    while(val!=0)
    {
    	i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_COMMAND,false,SI1143_NOP,1);
    	osDelay(10);
        i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_RESPONSE,false,&val,1);
    }
    do{
    	i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_COMMAND,false,&cmd,1);
    	osDelay(10);
        if(cmd==SI1143_RESET){
        	break;
        }
        osDelay(10);
		i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_RESPONSE,false,&val,1);

    }while(val==0);
}

int SI1143::getProximity(int numberOfMeasurements) // Read the data for the first LED
{
	uint8_t lowByte;
	uint8_t highByte;
	int stack = 0;
    int proximity = 0;

    command(SI1143_PSALS_FORCE);

    for(int r=numberOfMeasurements; r>0; r=r-1)
    {
    	i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_PS1_DATA0,false,&lowByte,1);
    	i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_PS1_DATA1,false,&highByte,1);
        stack = stack + (highByte * 256) + lowByte;
    }
    proximity = stack / numberOfMeasurements;

    return proximity;
}

int SI1143::getAmbientLight(int numberOfMeasurements) // Read the data for ambient light
{

    uint8_t lowByte;
    uint8_t highByte;
    int stack = 0;
    int ambientLight = 0;

    command(SI1143_PSALS_FORCE);

    for(int r=numberOfMeasurements; r>0; r=r-1)
    {
    	i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_ALS_VIS_DATA0,false,&lowByte,1);
    	i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_ALS_VIS_DATA1,false,&highByte,1);
        stack = stack + (highByte * 256) + lowByte;
    }
    ambientLight = stack / numberOfMeasurements;

    return ambientLight;
}

int SI1143::getInfraRedLight(int numberOfMeasurements) // Read the data for infrared light
{
    uint8_t lowByte;
	uint8_t highByte;
	int stack = 0;
	int infraRedLight = 0;

    command(SI1143_PSALS_FORCE);

    for(int r=numberOfMeasurements; r>0; r=r-1)
    {
    	i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_ALS_IR_DATA0,false,&lowByte,1);
		i2c->read_RT((SI1143_IR_ADDRESS<<1),SI1143_ALS_IR_DATA1,false,&highByte,1);
        stack = stack + (highByte * 256) + lowByte;
    }
    infraRedLight = stack / numberOfMeasurements;

    return infraRedLight;
}

void SI1143::configureInterrupts(){
	uint8_t interruptEnableValue = config->getInterruptEnable();

	i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_IRQ_ENABLE,false,0,1);
}

void SI1143::setProximitySensing1Threshold(){
	uint8_t thresholdLowByte = (config->getProximitySensing1Threshold()) & 0xFF;
	uint8_t thresholdHighByte = (config->getProximitySensing1Threshold()) >> 8;

	i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_PS1_TH0,false,&thresholdLowByte,1);
	i2c->write_RT((SI1143_IR_ADDRESS<<1),SI1143_PS1_TH1,false,&thresholdHighByte,1);

}


