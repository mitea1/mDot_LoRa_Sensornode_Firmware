/*
 * Application_MODE.cpp
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */

#include "ApplicationConfig.h"

ApplicationConfig::ApplicationConfig() {

}

ApplicationConfig::~ApplicationConfig() {

}

void ApplicationConfig::build(APPLICATION_MODE desiredMode) {
	switch (desiredMode) {
	case APPLICATION_MODE_1:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_1);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_2:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_1);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_3:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_4:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_1);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_5:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_6:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_1);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_7:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_8:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_1);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_9:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_10:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(RUNNING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_1);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_11:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_99:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_TEST:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_4);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_4);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_1);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_TEST_MAX44009:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_TEST_BME280:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_TEST_MPU9250:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_TEST_SI1143:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case APPLICATION_MODE_TEST_uBlox:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_0);
		setLORA_MODE(LORA_MODE_0_OFF);
		break;
	case APPLICATION_MODE_LORA_MEASUREMENT:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(RUNNING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_0);
		setLORA_MODE(LORA_MODE_1);
		break;
	case WEATHER_MEASUREMENT:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case ORIENTATATION_MEASUREMENT:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(SLEEPING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;
	case DISTANCE_MEASUREMENT:
		setStateTaskLight(SLEEPING);
		setStateTaskTemperature(SLEEPING);
		setStateTaskPressure(SLEEPING);
		setStateTaskHumidity(SLEEPING);
		setStateTaskAcceleration(SLEEPING);
		setStateTaskGyroscope(SLEEPING);
		setStateTaskTesla(SLEEPING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(SLEEPING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_3);
		setuBlox_MODE(uBLOX_MODE_3);
		setLORA_MODE(LORA_MODE_1);
		break;

	default:
		setStateTaskLight(RUNNING);
		setStateTaskTemperature(RUNNING);
		setStateTaskPressure(RUNNING);
		setStateTaskHumidity(RUNNING);
		setStateTaskAcceleration(RUNNING);
		setStateTaskGyroscope(RUNNING);
		setStateTaskTesla(RUNNING);
		setStateTaskProximity(RUNNING);
		setStateTaskGPS(RUNNING);
		setStateTaskLoRaMeasurement(SLEEPING);
		setStateTaskPowerMeasurement(SLEEPING);
		setMAX44009_MODE(MAX44009_MODE_1);
		setBME280_MODE(BME280_MODE_1);
		setMPU9250_MODE(MPU9250_MODE_1);
		setSI1143_MODE(SI1143_MODE_1);
		setuBlox_MODE(uBLOX_MODE_1);
		setLORA_MODE(LORA_MODE_1);
		break;
	}
}

MAX44009_MODE ApplicationConfig::getMAX44009_MODE() {
	return max44009Mode;
}

BME280_MODE ApplicationConfig::getBME280_MODE() {
	return bme280Mode;
}

MPU9250_MODE ApplicationConfig::getMPU9250_MODE() {
	return mpu9250Mode;
}

SI1143_MODE ApplicationConfig::getSI1143_MODE() {
	return si1143Mode;
}

uBLOX_MODE ApplicationConfig::getuBlox_MODE() {
	return ubloxMode;
}

LORA_MODE ApplicationConfig::getLORA_MODE(){
	return loraMode;
}

TASK_STATE ApplicationConfig::getStateTaskLight(){
	return stateTaskLight;
}

TASK_STATE ApplicationConfig::getStateTaskTemperature(){
	return stateTaskTemperature;
}

TASK_STATE ApplicationConfig::getStateTaskPressure(){
	return stateTaskPressure;
}

TASK_STATE ApplicationConfig::getStateTaskHumidity(){
	return stateTaskHumidity;
}

TASK_STATE ApplicationConfig::getStateTaskAcceleration(){
	return stateTaskAcceleration;
}

TASK_STATE ApplicationConfig::getStateTaskGyroscope(){
	return stateTaskGyroscope;
}

TASK_STATE ApplicationConfig::getStateTaskTesla(){
	return stateTaskTesla;
}

TASK_STATE ApplicationConfig::getStateTaskProximity(){
	return stateTaskProximity;
}

TASK_STATE ApplicationConfig::getStateTaskGPS(){
	return stateTaskGPS;
}

TASK_STATE ApplicationConfig::getStateTaskLoRaMeasurement(){
	return stateTaskLoraMeasurement;
}

TASK_STATE ApplicationConfig::getStateTaskPowerMeasurement(){
	return stateTaskPowerMeasurement;
}

LORA_STATE ApplicationConfig::getStateLoRa(){
	//TODO implement usage of this function
	return stateLoRa;
}

void ApplicationConfig::setMAX44009_MODE(MAX44009_MODE max44009Mode) {
	this->max44009Mode = max44009Mode;
}

void ApplicationConfig::setBME280_MODE(BME280_MODE bme280Mode) {
	this->bme280Mode = bme280Mode;
}

void ApplicationConfig::setMPU9250_MODE(MPU9250_MODE mpu9250Mode) {
	this->mpu9250Mode = mpu9250Mode;
}

void ApplicationConfig::setSI1143_MODE(SI1143_MODE si1143Mode) {
	this->si1143Mode = si1143Mode;
}

void ApplicationConfig::setuBlox_MODE(uBLOX_MODE ubloxMode) {
	this->ubloxMode = ubloxMode;
}

void ApplicationConfig::setLORA_MODE(LORA_MODE loraMode){
	this->loraMode = loraMode;
}

void ApplicationConfig::setStateTaskLight(TASK_STATE _stateTaskLight){
	this->stateTaskLight = _stateTaskLight;
}

void ApplicationConfig::setStateTaskTemperature(TASK_STATE _stateTaskTemperature){
	this->stateTaskTemperature = _stateTaskTemperature;
}

void ApplicationConfig::setStateTaskPressure(TASK_STATE _stateTaskPressure){
	this->stateTaskPressure = _stateTaskPressure;
}

void ApplicationConfig::setStateTaskHumidity(TASK_STATE stateTaskHumidity){
	this->stateTaskHumidity = stateTaskHumidity;
}

void ApplicationConfig::setStateTaskAcceleration(TASK_STATE stateTaskAcceleration){
	this->stateTaskAcceleration = stateTaskAcceleration;
}

void ApplicationConfig::setStateTaskGyroscope(TASK_STATE stateTaskGyroscope){
	this->stateTaskGyroscope = stateTaskGyroscope;
}

void ApplicationConfig::setStateTaskTesla(TASK_STATE stateTaskTesla){
	this->stateTaskTesla = stateTaskTesla;
}

void ApplicationConfig::setStateTaskProximity(TASK_STATE stateTaskProximity){
	this->stateTaskProximity = stateTaskProximity;
}

void ApplicationConfig::setStateTaskGPS(TASK_STATE stateTaskGPS){
	this->stateTaskGPS = stateTaskGPS;
}

void ApplicationConfig::setStateTaskLoRaMeasurement(TASK_STATE stateTaskLoRaMeasurement){
	this->stateTaskLoraMeasurement = stateTaskLoRaMeasurement;
}

void ApplicationConfig::setStateTaskPowerMeasurement(TASK_STATE stateTaskPowerMeasurement){
	this->stateTaskPowerMeasurement = stateTaskPowerMeasurement;
}

void ApplicationConfig::setStateLoRa(LORA_STATE stateLoRa){
	//TODO implement usage of this function
	this->stateLoRa = stateLoRa;
}


