/*
 * main.h
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */
#ifndef MAIN_H_
#define MAIN_H_

#include <Queue.h>
#include "BME280.h"
#include "BME280TemperatureMessage.h"
#include "BME280PressureMessage.h"
#include "BME280HumidityMessage.h"
#include "MAX44009.h"
#include "MAX44009Message.h"
#include "MPU9250.h"
#include "MPU9250AccelerationMessage.h"
#include "MPU9250GyroscopeMessage.h"
#include "MPU9250TeslaMessage.h"
#include "SI1143ProximityMessage.h"
#include "uBlox.h"
#include "UBloxGPSMessage.h"
#include "LoRaMeasuermentMessage.h"
#include "CommandMessage.h"

#define GPS_MESSAGE_LENGTH  36
#define BAUD_UART   9600
#define BAUD_USB    9600

/**
 * @defgroup Queue Lenghts
 * @{
 */

#define LIGHT_QUEUE_LENGHT					1
#define ACCELERATION_QUEUE_LENGHT			1
#define GYROSCOPE_QUEUE_LENGHT				1
#define TESLA_QUEUE_LENGHT					1
#define TEMPERATURE_QUEUE_LENGHT			1
#define PRESSURE_QUEUE_LENGHT				1
#define HUMIDITY_QUEUE_LENGHT				1
#define PROXIMITY_QUEUE_LENGHT				1
#define GPS_QUEUE_LENGHT					1
#define LORA_MEASUREMENT_QUEUE_LENGHT		1
#define COMMAND_QUEUE_LENGHT				1

/** @} */

/**
 * @defgroup Task Delays
 * @{
 */

#define LIGHT_TASK_DELAY_MS 			15000
#define TEMPERATURE_TASK_DELAY_MS 		15000
#define HUMIDITY_TASK_DELAY_MS 			15000
#define PRESSURE_TASK_DELAY_MS 			15000
#define ACCELERATION_TASK_DELAY_MS 		15000
#define GYROSCOPE_TASK_DELAY_MS 		15000
#define TESLA_TASK_DELAY_MS 			15000
#define PROXIMITY_TASK_DELAY_MS 		15000
#define GPS_TASK_DELAY_MS 				15000
#define LORA_MEASUREMENT_TASK_DELAY_MS 	15000
#define DATAHANLDER_TASK_DELAY_MS 		15000

/** @} */

/**
 * @defgroup LoRa Message IDs
 * @{
 */

#define MAX44009_MESSAGE_ID								"L"
#define UBLOX_GPS_MESSAGE_ITOW_ID						"G1"
#define UBLOX_GPS_MESSAGE_LONGITUDE_ID					"G2"
#define UBLOX_GPS_MESSAGE_LATITUDE_ID					"G3"
#define UBLOX_GPS_MESSAGE_HEIGHT_ID						"G4"
#define UBLOX_GPS_MESSAGE_HMSL_ID						"G5"
#define UBLOX_GPS_MESSAGE_HACC_ID						"G6"
#define UBLOX_GPS_MESSAGE_VACC_ID						"G7"
#define BME280_TEMPERATURE_MESSAGE_ID					"B1"
#define BME280_PRESSURE_MESSAGE_ID						"B2"
#define BME280_HUMIDITY_MESSAGE_ID						"B3"
#define MPU9250_X_ACCELERATION_MESSAGE_ID				"M1"
#define MPU9250_Y_ACCELERATION_MESSAGE_ID				"M2"
#define MPU9250_Z_ACCELERATION_MESSAGE_ID				"M3"
#define MPU9250_X_GYROSCOPE_MESSAGE_ID					"M4"
#define MPU9250_Y_GYROSCOPE_MESSAGE_ID					"M5"
#define MPU9250_Z_GYROSCOPE_MESSAGE_ID					"M6"
#define MPU9250_X_TESLA_MESSAGE_ID						"M7"
#define MPU9250_Y_TESLA_MESSAGE_ID						"M8"
#define MPU9250_Z_TESLA_MESSAGE_ID						"M9"
#define SI1143_PROXIMITY_MESSAGE_ID						"P1"

#define LORA_MEASURMENT_RSSI_MESSAGE_ID					"Z1"
#define LORA_MEASURMENT_SNR_MESSAGE_ID					"Z2"
#define LORA_MEASURMENT_SPREADING_FACTOR_MESSAGE_ID		"Z3"
#define LORA_MEASURMENT_TX_POWER_MESSAGE_ID				"Z4"

/** @} */



#define LORA_COMMAND_APPLICATION_MODE_1		"AM1"
#define LORA_COMMAND_APPLICATION_MODE_2		"AM2"
#define LORA_COMMAND_APPLICATION_MODE_3		"AM3"
#define LORA_COMMAND_APPLICATION_MODE_4		"AM4"

/**
 * @brief Special Bundle that can hold references to all queues. Used especially by the TaskDatahandler
 */
typedef struct QueueBundle{
	Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queueLight;
	Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queueTemperature;
	Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queuePressure;
	Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queueHumidity;
	Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queueAcceleration;
	Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queueGyro;
	Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queueTesla;
	Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queueProximity;
	Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queueGps;
	Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>* queueLoRaMeasurments;
	Queue<CommandMessage,COMMAND_QUEUE_LENGHT>* queueCommands;
};

/**
 * Task States. Define different States in which a task can be on the ApplicationConfig Level
 * Each task is either RUNNING or SLEEPING
 */
enum TASK_STATE {
	RUNNING = 1,//!< RUNNING
	SLEEPING = 0//!< SLEEPING
};

/**
 * LoRa States. Define different States in wich the LoRa Modul can be on the ApplicationConfig Level
 * It's either ON or OFF
 */
enum LORA_STATE {
	ON = 1,//!< ON
	OFF = 0//!< OFF
};


#endif /* MAIN_H_ */
