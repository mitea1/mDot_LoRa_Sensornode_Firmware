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

#ifndef TASKLIGHT_H_
#define TASKLIGHT_H_

/**
 * @class TaskLight
 * @brief This TaskLight Class handles the light measurement using the MAX44009.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskLight{
public:
	TaskLight(MAX44009*,Mutex*, Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>*);
	TaskLight(MAX44009*,Mutex*,Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskLight();

	/**
	 * Starts the task by building and its measurement
	 * @return
	 */
	osStatus start();

	/**
	 * Stops the task. Should only be used after start() was used
	 * @return
	 */
	osStatus stop();


	/**
	 * Gets the actual state of the Task either RUNNING or SLEEPING
	 * @return
	 */
	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	MAX44009* max44009;

	/**
	 * @brief A Callback function thats called by the mbed::Thread of this TaskClass
	 * @param
	 */
	static void callBack(void const *);

	/**
	 * @brief Attaches the idle_hook for this task
	 * @param
	 */
	void attachIdleHook(void (*fptr) (void));

	/**
	 * @brief A thread safe method that measures the light. After measuring the light
	 * it stores the value inside a MAX44009Message
	 */
	void measureLight();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueLight the queue where the MAX44009Message will be stored
	 */
	void setQueue(Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queueLight);

	/**
	 * @brief Sets the mutex thats used for a thread safe measurement
	 * @param mutexI2C the I2C mutex
	 */
	void setMutex(Mutex* mutexI2C);

	/**
	 * @brief Sets the priority of the Task
	 * @param priority priority of the Task
	 */
	void setPriority(osPriority priority);

	/**
	 * @brief Sets the size of the Task
	 * @param stackSize the stack size in Bytes
	 */
	void setStackSize(uint32_t stackSize);

	/**
	 * @brief Sets the stack pointer of for the task stack
	 * @param stackPointer
	 */
	void setStackPointer(unsigned char* stackPointer);

	/**
	 * @brief Sets the actual state of the Task.
	 * @param taskState either RUNNING or SLEEPING
	 */
	void setState(TASK_STATE taskState);

};
#endif /* TASKLIGHT_H_ */
