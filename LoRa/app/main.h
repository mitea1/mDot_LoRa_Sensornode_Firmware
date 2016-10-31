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
#define POWER_MEASUREMENT_QUEUE_LENGHT		1
#define COMMAND_QUEUE_LENGHT				1

/** @} */

/**
 * @defgroup Task Delays
 * @{
 */

#define LIGHT_TASK_DELAY_MS 				15000
#define TEMPERATURE_TASK_DELAY_MS 			15000
#define HUMIDITY_TASK_DELAY_MS 				15000
#define PRESSURE_TASK_DELAY_MS 				15000
#define ACCELERATION_TASK_DELAY_MS 			15000
#define GYROSCOPE_TASK_DELAY_MS 			15000
#define TESLA_TASK_DELAY_MS 				15000
#define PROXIMITY_TASK_DELAY_MS 			15000
#define GPS_TASK_DELAY_MS 					15000
#define LORA_MEASUREMENT_TASK_DELAY_MS 		15000
#define POWER_MEASUREMENT_TASK_DELAY_MS 	15000
#define DATAHANLDER_TASK_DELAY_MS 			15000
#define COMMANDHANLDER_TASK_DELAY_MS 		15000
#define APPLICATIONHANLDER_TASK_DELAY_MS 	15000

/** @} */

/**
 * @defgroup LoRa Message IDs
 * @{
 */

#define MAX44009_MESSAGE_ID								"L"
#define MAX44009_BINARY_MESSAGE_ID						0x4C
#define UBLOX_GPS_MESSAGE_ITOW_ID						"G1"
#define UBLOX_GPS_MESSAGE_LONGITUDE_ID					"G2"
#define UBLOX_GPS_BINARY_MESSAGE_LONGITUDE_ID			0x4732
#define UBLOX_GPS_MESSAGE_LATITUDE_ID					"G3"
#define UBLOX_GPS_BINARY_MESSAGE_LATITUDE_ID			0x4733
#define UBLOX_GPS_MESSAGE_HEIGHT_ID						"G4"
#define UBLOX_GPS_MESSAGE_HMSL_ID						"G5"
#define UBLOX_GPS_MESSAGE_HACC_ID						"G6"
#define UBLOX_GPS_MESSAGE_VACC_ID						"G7"
#define BME280_TEMPERATURE_MESSAGE_ID					"B1"
#define BME280_TEMPERATURE_BINARY_MESSAGE_ID			0x4231
#define BME280_PRESSURE_MESSAGE_ID						"B2"
#define BME280_PRESSURE_BINARY_MESSAGE_ID				0x4232
#define BME280_HUMIDITY_MESSAGE_ID						"B3"
#define BME280_HUMIDITY_BINARY_MESSAGE_ID				0x4233
#define MPU9250_X_ACCELERATION_MESSAGE_ID				"M1"
#define MPU9250_X_ACCELERATION_BINARY_MESSAGE_ID		0x4D31
#define MPU9250_Y_ACCELERATION_MESSAGE_ID				"M2"
#define MPU9250_Y_ACCELERATION_BINARY_MESSAGE_ID		0x4D32
#define MPU9250_Z_ACCELERATION_MESSAGE_ID				"M3"
#define MPU9250_Z_ACCELERATION_BINARY_MESSAGE_ID		0x4D33
#define MPU9250_X_GYROSCOPE_MESSAGE_ID					"M4"
#define MPU9250_X_GYROSCOPE_BINARY_MESSAGE_ID			0x4D34
#define MPU9250_Y_GYROSCOPE_MESSAGE_ID					"M5"
#define MPU9250_Y_GYROSCOPE_BINARY_MESSAGE_ID			0x4D35
#define MPU9250_Z_GYROSCOPE_MESSAGE_ID					"M6"
#define MPU9250_Z_GYROSCOPE_BINARY_MESSAGE_ID			0x4D36
#define MPU9250_X_TESLA_MESSAGE_ID						"M7"
#define MPU9250_X_TESLA_BINARY_MESSAGE_ID				0x4D37
#define MPU9250_Y_TESLA_MESSAGE_ID						"M8"
#define MPU9250_Y_TESLA_BINARY_MESSAGE_ID				0x4D38
#define MPU9250_Z_TESLA_MESSAGE_ID						"M9"
#define MPU9250_Z_TESLA_BINARY_MESSAGE_ID				0x4D39
#define INA219_SHUNT_VOLTAGE_MESSAGE_ID					"I1"
#define INA219_SHUNT_VOLTAGE_BINARY_MESSAGE_ID			0x4931
#define INA219_BUS_VOLTAGE_MESSAGE_ID					"I2"
#define INA219_BUS_VOLTAGE_BINARY_MESSAGE_ID			0x4932
#define INA219_CURRENT_MESSAGE_ID						"I3"
#define INA219_CURRENT_BINARY_MESSAGE_ID				0x4933
#define INA219_POWER_MESSAGE_ID							"I4"
#define INA219_POWER_BINARY_MESSAGE_ID					0x4934
#define SI1143_PROXIMITY_MESSAGE_ID						"P1"
#define SI1143_PROXIMITY_BINARY_MESSAGE_ID				0x5131

#define LORA_MEASURMENT_RSSI_MESSAGE_ID					"Z1"
#define LORA_MEASURMENT_SNR_MESSAGE_ID					"Z2"
#define LORA_MEASURMENT_SPREADING_FACTOR_MESSAGE_ID		"Z3"
#define LORA_MEASURMENT_TX_POWER_MESSAGE_ID				"Z4"




/**
 * @defgroup Command messages that can be received via LoRa Downlink
 * @{
 */
#define LORA_COMMAND_ACTION_0				0x00
#define LORA_COMMAND_ACTION_1				0x01
#define LORA_COMMAND_ACTION_2				0x02
/** @} */


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
	Queue<LoRaMeasurementMessage,POWER_MEASUREMENT_QUEUE_LENGHT>* queuePowerMeasurments;
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
