/**
 * @file TaskTemperature.h
 *
 * @author Adrian
 * @date 30.05.2016
 *
 */

#include "BME280.h"
#include "BME280TemperatureMessage.h"
#include "main.h"
#include "Task.h"

#ifndef TASKTEMPERATURE_H_
#define TASKTEMPERATURE_H_

/**
 * @class TaskTemperature
 * @brief This TaskTemperature Class handles the temperature measurement using the BME280.
 * Starting the task using the start() starts the measurement of all axis.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskTemperature : public Task {
public:
	TaskTemperature(BME280*,Mutex*, Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>*);
	TaskTemperature(BME280*,Mutex*,Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskTemperature();

private:
	rtos::Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queue;

	BME280* bme280;

	/**
	 * @brief A thread safe method that measures the temperature. After measuring
	 * the temperature it stores the data inside a BME280TemperatureMessage
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueGyro the queue where the MPU9250GyroscopeMessage will be stored
	 */
	void setQueue(Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queueTemperature);

};

#endif /* TASKTEMPERATURE_H_ */
