/**
 * @file TaskGyroscope.h
 *
 * @author Adrian
 * @date 30.05.2016
 *
 */

#include "MPU9250.h"
#include "MPU9250GyroscopeMessage.h"
#include "main.h"
#include "Task.h"

#ifndef TASKGYROSCOPE_H_
#define TASKGYROSCOPE_H_

/**
 * @class TaskGyroscope
 * @brief This TaskGyroscope Class handles the gyroscope measurement using the MPU9250.
 * Starting the task using the start() starts the measurement of all axis.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskGyroscope : public Task {
public:
	TaskGyroscope(MPU9250*,Mutex*, Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>*);
	TaskGyroscope(MPU9250*,Mutex*,Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskGyroscope();

private:

	rtos::Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queue;

	MPU9250* mpu9250;

	/**
	 * @brief A thread safe method that acquires data from the gyroscope. After acquiring data from the
	 * it stores the data inside a MPU9250GyroscopeMessage
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueGyro the queue where the MPU9250GyroscopeMessage will be stored
	 */
	void setQueue(Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queueGyro);

};

#endif /* TASKGYROSCOPE_H_ */
