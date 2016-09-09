/**
 * @file TaskPressure.h
 *
 * @author Adrian
 * @date 30.05.2016
 *
 */

#include "BME280.h"
#include "BME280PressureMessage.h"
#include "main.h"
#include "Task.h"

#ifndef TASKPRESSURE_H_
#define TASKPRESSURE_H_

/**
 * @class TaskPressure
 * @brief This TaskPressure Class handles the pressure measurement using the BME280.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskPressure : public Task {
public:
	TaskPressure(BME280*,Mutex*, Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>*);
	TaskPressure(BME280*,Mutex*,Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskPressure();

private:
	rtos::Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue;
	BME280* bme280;

	/**
	 * @brief A thread safe method that measures the actual pressure. After measuring the pressure
	 * it stores the value inside a BME280PressureMessage
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queuePressure the queue where the BME280PressureMessage will be stored
	 */
	void setQueue(Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queuePressure);
};

#endif /* TASKPRESSURE_H_ */
