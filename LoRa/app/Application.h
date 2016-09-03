/*
 * 	Application.h
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */

#include "ApplicationConfig.h"
#include "mbed.h"
#include "rtos.h"
#include "I2C_RT.h"
#include "MAX44009.h"
#include "BME280.h"
#include "MPU9250.h"
#include "SI1143.h"
#include "uBlox.h"
#include "mDot.h"
#include "LoRa.h"
#include "TaskLight.h"
#include "TaskTemperature.h"
#include "TaskHumidity.h"
#include "TaskPressure.h"
#include "TaskAcceleration.h"
#include "TaskGyroscope.h"
#include "TaskTesla.h"
#include "TaskProximity.h"
#include "TaskGPS.h"
#include "TaskLoRaMeasurement.h"
#include "TaskDatahandler.h"
#include "main.h"

#ifndef SENSORHANDLER_H_
#define SENSORHANDLER_H_

class Application {
public:
	Application();
	virtual ~Application();

	/**
	 * @brief Start the Application in the desired Mode
	 * @return
	 */
	void init(APPLICATION_MODE desiredMode);

private:
	RawSerial* uart;
	RawSerial* debugSerial;
	I2C_RT* i2c_rt;
	mDot* dot;
	LoRa* lora;

	TaskLight* taskLight;
	TaskTemperature* taskTemperature;
	TaskPressure* taskPressure;
	TaskHumidity* taskHumidity;
	TaskAcceleration* taskAcceleration;
	TaskGyroscope* taskGyroscope;
	TaskTesla* taskTesla;
	TaskProximity* taskProximity;
	TaskGPS* taskGps;
	TaskLoRaMeasurement* taskLoRaMeasurement;
	TaskDatahandler* taskDataHandler;

	rtos::Mutex* mutexI2C;
	rtos::Mutex* mutexUART1;
	rtos::Mutex mutexBME280;
	rtos::Mutex mutexMAX44009;
	rtos::Mutex mutexMPU9250;
	rtos::Mutex mutexSi4103;
	rtos::Mutex mutexUBlox;
	rtos::Mutex* mutexLoRa;

	Queue<MAX44009Message,LIGHT_QUEUE_LENGHT> queueLight;
	Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT> queueTemperature;
	Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT> queuePressure;
	Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT> queueHumidity;
	Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT> queueAcceleration;
	Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT> queueGyro;
	Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT> queueTesla;
	Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT> queueProximity;
	Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT> queueGps;
	Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT> queueLoRaMeasurements;
	Queue<CommandMessage,COMMAND_QUEUE_LENGHT> queueCommands;

	QueueBundle queueBundle;

	uBlox* gpsSensor;
	MAX44009* max44009;
	BME280*	bme280;
	MPU9250* mpu9250;
	SI1143* si1143;

	ApplicationConfig* config;

	/**
	 * @brief Initializes all Interfaces such as I2C, UART and a Debug Serial via USB
	 */
	void initInterfaces();

	/**
	 * @brief Initializes (builds) all Sensors in their specific modes
	 */
	void initSensors();

	/**
	 * @brief Initializes (builds) all Tasks so that they are ready to run
	 */
	void initTasks();

	/**
	 * @brief Initializes (builds) all Mutexes so that they are ready to be used
	 */
	void initMutexes();

	/**
	 * @brief Initializes (builds) the ApplicationConfig which contains information about
	 * which Task has to be run and how the sensors have to be configured
	 */
	void initApplicationConfig();

	/**
	 * @brief Initializes (builds) the QueueBundle
	 */
	void initQueueBundle();

	/**
	 * @brief Stops all tasks that are currently running. Used to define a defined state to start the application
	 * in a new mode or when using a transition between two application modes it is neccessary to stop all task before
	 * starting them again
	 */
	void stopAllRunningSensorTasks();

	/**
	 * @brief Starts all task which are allowed to run by the Application Config
	 */
	void startRunnableSensorTasks();

	/**
	 * @brief Configures and builds the sensors according to they SensorMode specific parameters
	 */
	void configureSensors();

	/**
	 * @brief Configures and builds the LoRa Device according to its Mode specific parameters
	 */
	void configureLora();

};

#endif /* APPLICATION_H_ */
