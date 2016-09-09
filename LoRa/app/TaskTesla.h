/**
 * @file TaskTesla.h
 *
 * @author Adrian
 * @date 01.06.2016
 *
 */

#include "MPU9250.h"
#include "MPU9250TeslaMessage.h"
#include "main.h"
#include "Task.h"

#ifndef APP_TASKTESLA_H_
#define APP_TASKTESLA_H_

/**
 * @class TaskTesla
 * @brief This TaskTesla Class handles the tesla measurement using the MPU9250.
 * Starting the task using the start() starts the measurement of all axis.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskTesla : public Task {
public:
	TaskTesla(MPU9250*,Mutex*, Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*);
	TaskTesla(MPU9250*,Mutex*,Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskTesla();

private:
	rtos::Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue;

	MPU9250* mpu9250;

	/**
	 * @brief A thread safe method that measures Teslas of each axis. After the measurement
	 * it stores the data inside a MPU9250TelsaMessage
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueTesla the queue where the MPU9250TeslaMessage will be stored
	 */
	void setQueue(Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*queueTesla);
};

#endif /* APP_TASKTESLA_H_ */
