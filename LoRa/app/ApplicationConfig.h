/*
 * ApplicationConfig.h
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */
#include "BME280Config.h"
#include "MPU9250Config.h"
#include "uBloxConfig.h"
#include "MAX44009Config.h"
#include "SI1143Config.h"
#include "LoRaConfig.h"
#include "main.h"
#ifndef APPLICATIONCONFIG_H_
#define APPLICATIONCONFIG_H_

/**
 * Application Modes. Modes define different Usages of the LoRa sensor node
 */
enum APPLICATION_MODE {
	APPLICATION_MODE_1,               //!< APPLICATION_MODE_1
	APPLICATION_MODE_2,               //!< APPLICATION_MODE_2
	APPLICATION_MODE_3,               //!< APPLICATION_MODE_3
	APPLICATION_MODE_4,               //!< APPLICATION_MODE_4
	APPLICATION_MODE_5,               //!< APPLICATION_MODE_5
	APPLICATION_MODE_6,               //!< APPLICATION_MODE_6
	APPLICATION_MODE_7,               //!< APPLICATION_MODE_7
	APPLICATION_MODE_8,               //!< APPLICATION_MODE_8
	APPLICATION_MODE_9,               //!< APPLICATION_MODE_9
	APPLICATION_MODE_10,              //!< APPLICATION_MODE_10
	APPLICATION_MODE_11,              //!< APPLICATION_MODE_11
	APPLICATION_MODE_99,              //!< APPLICATION_MODE_99
	APPLICATION_MODE_TEST,            //!< APPLICATION_MODE_TEST
	APPLICATION_MODE_TEST_MAX44009,   //!< APPLICATION_MODE_TEST_MAX44009
	APPLICATION_MODE_TEST_BME280,     //!< APPLICATION_MODE_TEST_BME280
	APPLICATION_MODE_TEST_MPU9250,    //!< APPLICATION_MODE_TEST_MPU9250
	APPLICATION_MODE_TEST_SI1143,     //!< APPLICATION_MODE_TEST_SI1143
	APPLICATION_MODE_TEST_uBlox,      //!< APPLICATION_MODE_TEST_uBlox
	APPLICATION_MODE_LORA_MEASUREMENT,//!< APPLICATION_MODE_LORA_MEASUREMENT
	WEATHER_MEASUREMENT,     				//!< WEATHER_STATION
	ORIENTATATION_MEASUREMENT,				//!< ORIENTATATION_SENSOR
	DISTANCE_MEASUREMENT,     				//!< DISTANCE_SENSOR
};


class ApplicationConfig {
public:
	ApplicationConfig();
	virtual ~ApplicationConfig();

	/**
	 * @brief Generates a configuration according to the chosen APPLICATION_MODE
	 * @param desiredMode the mode to build the configuration according to
	 */
	void build(APPLICATION_MODE desiredMode);


	/**
	 * @brief Get Information about the MAX44009_MODE of the actual ApplicationConfig
	 * @return the actual MAX44009_MODE
	 */
	MAX44009_MODE getMAX44009_MODE();

	/**
	 * @brief Get Information about the BME280_MODE of the actual ApplicationConfig
	 * @return the actual BME280_MODE
	 */
	BME280_MODE getBME280_MODE();

	/**
	 * @brief Get Information about the MPU9250_MODE of the actual ApplicationConfig
	 * @return the actual MPU9250_MODE
	 */
	MPU9250_MODE getMPU9250_MODE();

	/**
	 * @brief Get Information about the SI1143_MODE of the actual ApplicationConfig
	 * @return the actual SI1143_MODE
	 */
	SI1143_MODE getSI1143_MODE();

	/**
	 * @brief Get Information about the uBLOX_MODE of the actual ApplicationConfig
	 * @return the actual uBLOX_MODE
	 */
	uBLOX_MODE getuBlox_MODE();

	/**
	 * @brief Get Information about the LORA_MODE of the actual ApplicationConfig
	 * @return the actual LORA_MODE
	 */
	LORA_MODE getLORA_MODE();


	/**
	 * @brief Get Information about the TASK_STATE of the TaskLight in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskLight
	 */
	TASK_STATE getStateTaskLight();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskTemperature in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskTemperature
	 */
	TASK_STATE getStateTaskTemperature();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskPressure in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskPressure
	 */
	TASK_STATE getStateTaskPressure();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskHumidity in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskHumidity
	 */
	TASK_STATE getStateTaskHumidity();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskAcceleration in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskAcceleration
	 */
	TASK_STATE getStateTaskAcceleration();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskGyroscope in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskGyroscope
	 */
	TASK_STATE getStateTaskGyroscope();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskTesla in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskTesla
	 */
	TASK_STATE getStateTaskTesla();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskProximity in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskProximity
	 */
	TASK_STATE getStateTaskProximity();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskGPS in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskGPS
	 */
	TASK_STATE getStateTaskGPS();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskLoRaMeasurement in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskLoRaMeasurement
	 */
	TASK_STATE getStateTaskLoRaMeasurement();

	/**
	 * @brief Get Information about the TASK_STATE of the TaskPowerMeasurement in the actual ApplicationConfig
	 * @return the actual TASK_STATE (RUNNING,SLEEPING) of TaskPowerMeasurement
	 */
	TASK_STATE getStateTaskPowerMeasurement();

	/**
	 * @brief Get Information about the LORA_STATE of the LoRa Module in the actual ApplicationConfig
	 * @return the actual LORA_STATE (ON,OFF) of TaskLoRaMeasurement
	 */
	LORA_STATE getStateLoRa();

private:
	MAX44009_MODE max44009Mode;
	BME280_MODE bme280Mode;
	MPU9250_MODE mpu9250Mode;
	SI1143_MODE si1143Mode;
	uBLOX_MODE ubloxMode;
	LORA_MODE loraMode;

	TASK_STATE stateTaskLight;
	TASK_STATE stateTaskTemperature;
	TASK_STATE stateTaskPressure;
	TASK_STATE stateTaskHumidity;
	TASK_STATE stateTaskAcceleration;
	TASK_STATE stateTaskGyroscope;
	TASK_STATE stateTaskTesla;
	TASK_STATE stateTaskProximity;
	TASK_STATE stateTaskGPS;
	TASK_STATE stateTaskLoraMeasurement;
	TASK_STATE stateTaskPowerMeasurement;

	LORA_STATE stateLoRa;

	/**
	 * @brief Sets the MAX44009_MODE for that the MAX44009 Sensor has to be initialized for the actual ApplicationConfig
	 * @param the diseredMode
	 */
	void setMAX44009_MODE(MAX44009_MODE desiredMode);

	/**
	 * @brief Sets the BME280_MODE for that the BME280 Sensor has to be initialized for the actual ApplicationConfig
	 * @param the diseredMode
	 */
	void setBME280_MODE(BME280_MODE desiredMode);

	/**
	 * @brief Sets the MPU9250_MODE for that the MPU9250 Sensor has to be initialized for the actual ApplicationConfig
	 * @param the diseredMode
	 */
	void setMPU9250_MODE(MPU9250_MODE desiredMode);

	/**
	 * @brief Sets the SI1143_MODE for that the SI1143 Sensor has to be initialized for the actual ApplicationConfig
	 * @param the diseredMode
	 */
	void setSI1143_MODE(SI1143_MODE desiredMode);

	/**
	 * @brief Sets the uBLOX_MODE for that the uBlox Sensor has to be initialized for the actual ApplicationConfig
	 * @param the diseredMode
	 */
	void setuBlox_MODE(uBLOX_MODE desiredMode);

	/**
	 * @brief Sets the LORA_MODE for that the LORA device has to be initialized for the actual ApplicationConfig
	 * @param the diseredMode
	 */
	void setLORA_MODE(LORA_MODE desiredMode);


	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskLight for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskLight(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskTemperature for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskTemperature(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskPressure for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskPressure(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskHumidity for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskHumidity(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskAcceleration for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskAcceleration(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskGyroscope for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskGyroscope(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskTesla for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskTesla(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskProximity for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskProximity(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskGPS for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskGPS(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskLoRaMeasurement for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskLoRaMeasurement(TASK_STATE desiredState);

	/**
	 * @brief Sets the TASK_STATE (RUNNING,SLEEPING) of TaskPowerMeasurement for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateTaskPowerMeasurement(TASK_STATE desiredState);

	/**
	 * @brief Sets the LORA_STATE (ON,OFF) of LoRa Device for the actual ApplicationConfig
	 * @param the desired State
	 */
	void setStateLoRa(LORA_STATE);

};

#endif /* APPLICATIONCONFIG_H_ */
