/**
 * @file TaskLight.h
 *
 * @author Adrian
 * @date 27.05.2016
 *
 */

#include <Thread.h>
#include <Queue.h>
#include <Mutex.h>
#include "MAX44009.h"
#include "MAX44009Message.h"
#include "main.h"
#include "Task.h"

#ifndef TASKLIGHT_H_
#define TASKLIGHT_H_

/**
 * @class TaskLight
 * @brief This TaskLight Class handles the light measurement using the MAX44009.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskLight : public Task{
public:
	TaskLight(MAX44009*,Mutex*, Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>*);
	TaskLight(MAX44009*,Mutex*,Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskLight();

private:
	rtos::Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue;

	MAX44009* max44009;

	/**
	 * @brief A thread safe method that measures the light. After measuring the light
	 * it stores the value inside a MAX44009Message
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueLight the queue where the MAX44009Message will be stored
	 */
	void setQueue(Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queueLight);

};
#endif /* TASKLIGHT_H_ */
