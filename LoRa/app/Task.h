/*
 * Task.h
 *
 *  Created on: Sep 9, 2016
 *      Author: Adrian
 */
#include "main.h"

#ifndef TASK_H_
#define TASK_H_

class Task {
public:
	Task();
	virtual ~Task();

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

protected:
	rtos::Thread* thread;
	rtos::Mutex* mutexInterface ;
	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

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
	 * @brief A thread safe method that measures the acceleration. After measuring the acceleration
	 * of each axis it stores the value inside a MPU9250AccelerationMessage
	 */
	virtual void measure() = 0;


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
	 * @brief Sets the actual state of the Task
	 * @param taskState either RUNNING or SLEEPING
	 */
	void setState(TASK_STATE taskState);
};

#endif /* TASK_H_ */
