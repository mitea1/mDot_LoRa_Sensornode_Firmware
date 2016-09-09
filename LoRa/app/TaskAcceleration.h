/**
 * @file TaskAcceleration.h
 *
 * @author Adrian
 * @date 30.05.2016
 *
 */
#include "MPU9250.h"
#include "MPU9250AccelerationMessage.h"
#include "main.h"
#include "Task.h"

#ifndef TASKACCELERATION_H_
#define TASKACCELERATION_H_

/**
 * @class TaskAcceleration
 * @brief This TaskAcceleration Class handles the acceleration measurement using the MPU9250.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskAcceleration : public Task {
public:
	TaskAcceleration(MPU9250*,Mutex*, Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>*);
	TaskAcceleration(MPU9250*,Mutex*,Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskAcceleration();

private:

	MPU9250* mpu9250;
	rtos::Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queue;

	/**
	 * @brief A thread safe method that measures the acceleration. After measuring the acceleration
	 * of each axis it stores the value inside a MPU9250AccelerationMessage
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueAcceleration the queue where the MPU9250AccelerationMessage will be stored
	 */
	void setQueue(Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queue);

};

#endif /* TASKACCELERATION_H_ */
