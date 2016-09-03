/*
 * BME280.cpp
 *
 *  Created on: 18.05.2016
 *      Author: Adrian
 */

#include "BME280.h"

BME280::BME280(I2C_RT* i2c){
	setI2C(i2c);
	this->config = new BME280Config();
}

BME280::~BME280() {
	// TODO Auto-generated destructor stub
}

void BME280::init(BME280_MODE desiredMode){

	config->build(desiredMode);

	setOversamplingHumidity(config->getOversamplingHumidity());
	setOversamplingTemperature(config->getOversamplingTemperature());
	setOversamplingPressure(config->getOversamplingPressure());
	setMode(config->getMode());

	getTrimValuesHumidity();
	getTrimValuesPressure();
	getTrimValuesTemperature();
}

void BME280::setI2C(I2C_RT* i2c_rt){
	this->i2c = i2c_rt;
}

uint32_t BME280::getHumidity(){

	// Data Containers
	uint8_t msbRegisterData[1];
	uint8_t lsbRegisterData[1];

	i2c->read_RT(
			BME280_SENSOR_ADDRESS,BME280_SENSOR_HUM_MSB,false,msbRegisterData,1);
	i2c->read_RT(
			BME280_SENSOR_ADDRESS,BME280_SENSOR_HUM_LSB,false,lsbRegisterData,1);

	int32_t temp_fine = getTemperature();

	int32_t humRaw = (int32_t) (msbRegisterData[0]<<8|lsbRegisterData[0]);
	uint32_t hum_fine = this->compensateHumidity(humRaw,temp_fine);

	return hum_fine;

}

float BME280::getHumidityFloat(){
	return (float) getHumidity()/ 1024;
}

uint32_t BME280::getPressure(){

	// Data Containers
	uint8_t msbRegisterData[1];
	uint8_t lsbRegisterData[1];
	uint8_t xlsbRegisterData[1];

	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_PRESS_MSB,false,msbRegisterData,1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_PRESS_LSB,false,lsbRegisterData,1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_PRESS_XLSB,false,xlsbRegisterData, 1);

	int32_t temp_fine = getTemperature();

	int32_t pressRaw = (int32_t) (msbRegisterData[0]<<12|lsbRegisterData[0]<<4|lsbRegisterData[0]);
	uint32_t press_fine = compensatePressure(pressRaw,temp_fine);

	return press_fine;
}

float BME280::getPressureFloat(){
	return (float)getPressure()/256;
}

int32_t BME280::getTemperature(){
	uint8_t msbRegisterData[1];
	uint8_t lsbRegisterData[1];
	uint8_t xlsbRegisterData[1];

	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_TEMP_MSB,
			false,msbRegisterData,1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_TEMP_LSB,
			false,lsbRegisterData,1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_TEMP_XLSB,
			false,xlsbRegisterData,1);

	int32_t tempRaw = (int32_t) (msbRegisterData[0]<<12|lsbRegisterData[0]<<4|xlsbRegisterData[0]);
	int32_t tempFine = compensateTemperature(tempRaw);

	return tempFine;
}

float BME280::getTemperatureFloat(){
	int32_t temperature = this->getTemperature();

	return (float)(temperature)/100;
}

void BME280::getTrimValuesHumidity(){
	// Data Container for Trim Values Humidity
	uint8_t digH1Raw[1];
	uint8_t digH2Raw[2];
	uint8_t digH3Raw[1];
	uint8_t digH4Raw[2];
	uint8_t digH5Raw[2];
	uint8_t digH6Raw[1];

	// Get the Trim parameters for the exact calculation of the Humidity
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH1_LSB,0,&digH1Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH2_LSB,0,&digH2Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH2_MSB,0,&digH2Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH3_LSB,0,&digH3Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH4_LSB,0,&digH4Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH4_MSB,0,&digH4Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH5_LSB,0,&digH5Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH5_MSB,0,&digH5Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digH6_LSB,0,&digH6Raw[0],1);

	// Convert data into values
	digH1=digH1Raw[0];
	digH2=(digH2Raw[1]<<8)|digH2Raw[0];
	digH3=digH3Raw[0];
	digH4=(digH4Raw[1]<<4)|(digH4Raw[0] & 0x0F);
	digH5=(4>>(digH5Raw[1] & 0xF0))|(digH5Raw[0]<<4);
	digH6=digH6Raw[0];
}

void BME280::getTrimValuesPressure(){
	// Data Container for Trim Values Pressure
	uint8_t digP1Raw[2];
	uint8_t digP2Raw[2];
	uint8_t digP3Raw[2];
	uint8_t digP4Raw[2];
	uint8_t digP5Raw[2];
	uint8_t digP6Raw[2];
	uint8_t digP7Raw[2];
	uint8_t digP8Raw[2];
	uint8_t digP9Raw[2];

	// Get the Trim parameters for the exact calculation of the Pressure
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP1_LSB,0,&digP1Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP1_MSB,0,&digP1Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP2_LSB,0,&digP2Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP2_MSB,0,&digP2Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP3_LSB,0,&digP3Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP3_MSB,0,&digP3Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP4_LSB,0,&digP4Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP4_MSB,0,&digP4Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP5_LSB,0,&digP5Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP5_MSB,0,&digP5Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP6_LSB,0,&digP6Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP6_MSB,0,&digP6Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP7_LSB,0,&digP7Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP7_MSB,0,&digP7Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP8_LSB,0,&digP8Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP8_MSB,0,&digP8Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP9_LSB,0,&digP9Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digP9_MSB,0,&digP9Raw[1],1);

	// Convert data into values
	digP1=(digP1Raw[1]<<8)|digP1Raw[0];
	digP2=(digP2Raw[1]<<8)|digP2Raw[0];
	digP3=(digP3Raw[1]<<8)|digP3Raw[0];
	digP4=(digP4Raw[1]<<8)|digP4Raw[0];
	digP5=(digP5Raw[1]<<8)|digP5Raw[0];
	digP6=(digP6Raw[1]<<8)|digP6Raw[0];
	digP7=(digP7Raw[1]<<8)|digP7Raw[0];
	digP8=(digP8Raw[1]<<8)|digP8Raw[0];
	digP9=(digP9Raw[1]<<8)|digP9Raw[0];
}

void BME280::getTrimValuesTemperature(){
	// Data Container for Trim Values Temperature
	uint8_t digT1Raw[2];
	uint8_t digT2Raw[2];
	uint8_t digT3Raw[2];

	// Get the Trim parameters for the exact calculation of the Temperature
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digT1_LSB,0,&digT1Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digT1_MSB,0,&digT1Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digT2_LSB,0,&digT2Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digT2_MSB,0,&digT2Raw[1],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digT3_LSB,0,&digT3Raw[0],1);
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_digT3_MSB,0,&digT3Raw[1],1);

	// Convert data into values
	digT1=(digT1Raw[1]<<8)|digT1Raw[0];
	digT2=(digT2Raw[1]<<8)|digT2Raw[0];
	digT3=(digT3Raw[1]<<8)|digT3Raw[0];

}

void BME280::setWeatherMonitoringMode(){
	uint8_t configuration_1 = BME280_WHEAT_OVRS_T_P;
	uint8_t configuration_2 = BME280_WHEAT_OVRS_H;

	i2c->write_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_HUM,false,&configuration_2,1);
	i2c->write_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_MEAS,false,&configuration_1,1);

}

void BME280::setOversamplingTemperature(uint8_t oversamplingTemperature){
	uint8_t oldRegisterValue;
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_MEAS,false,
			&oldRegisterValue,1);

	uint8_t registerValue = (oversamplingTemperature << 5) | oldRegisterValue;
	i2c->write_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_MEAS,false,
			&registerValue,1);
}

void BME280::setOversamplingPressure(uint8_t oversamplingPressure){
	uint8_t oldRegisterValue;
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_MEAS,false,
			&oldRegisterValue,1);

	uint8_t registerValue = (oversamplingPressure << 2) | oldRegisterValue;
	i2c->write_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_MEAS,false,
			&registerValue,1);
}

void BME280::setOversamplingHumidity(uint8_t oversamplingHumdity){
	uint8_t oldRegisterValue;
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_HUM,false,
			&oldRegisterValue,1);

	uint8_t newRegisterValue = oversamplingHumdity|oldRegisterValue;
	i2c->write_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_HUM,false,
			&newRegisterValue,1);
}

void BME280::setMode(uint8_t mode){
	uint8_t oldRegisterValue;
	i2c->read_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_MEAS,false,
			&oldRegisterValue,1);

	uint8_t registerValue = mode | oldRegisterValue;
	i2c->write_RT(BME280_SENSOR_ADDRESS,BME280_SENSOR_CTRL_MEAS,false,
				&registerValue,1);
}

int32_t BME280::compensateHumidity(int32_t adc_H,int32_t temp_fine)
{
	int32_t v_x1_u32r;

	v_x1_u32r =  temp_fine - ((int32_t)76800);

	v_x1_u32r = (((((adc_H << 14) - (((int32_t)digH4) << 20) - (((int32_t)digH5) * v_x1_u32r)) +
			((int32_t)16384)) >> 15) * (((((((v_x1_u32r * ((int32_t)digH6)) >> 10) * (((v_x1_u32r *
					((int32_t)digH3)) >> 11) + ((int32_t)32768))) >> 10) + ((int32_t)2097152)) *
					((int32_t)digH2) + 8192) >> 14));

	v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((int32_t)digH1)) >> 4));
	v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
	v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);

	return (int32_t)(v_x1_u32r>>12);
}

int64_t BME280::compensatePressure(int32_t adc_P, int32_t temp_fine)
{
	int64_t var1, var2, p;
	var1 = ((int64_t)temp_fine) - 128000;
	var2 = var1 * var1 * (int64_t)digP6;
	var2 = var2 + ((var1*(int64_t)digP5)<<17);
	var2 = var2 + (((int64_t)digP4)<<35);
	var1 = ((var1 * var1 * (int64_t)digP3)>>8) + ((var1 * (int64_t)digP2)<<12);
	var1 = (((((int64_t)1)<<47)+var1))*((int64_t)digP1)>>33;
	if (var1 == 0)
	{
		return 0; // avoid exception caused by division by zero
	}
	p = ((int64_t)1048576)-adc_P;
	p = (((p<<31)-var2)*((int64_t)3125))/var1;
	var1 = (((int64_t)digP9) * (p>>13) * (p>>13)) >> 25;
	var2 = (((int64_t)digP8) * p) >> 19;
	p = ((p + var1 + var2) >> 8) + (((int64_t)digP7)<<4);
	return (int32_t)p;
}

int32_t BME280::compensateTemperature(int32_t adc_T)
{
	int32_t var1, var2, T;
	var1  = ((((adc_T>>3) - ((int32_t)digT1<<1))) * ((int32_t)digT2)) >> 11;
	var2  = (((((adc_T>>4) - ((int32_t)digT1)) * ((adc_T>>4) - ((int32_t)digT1))) >> 12) *
			((int32_t)digT3)) >> 14;
	int32_t t_fine = var1 + var2;
	T  = (t_fine * 5 + 128) >> 8;
	return T;
}
