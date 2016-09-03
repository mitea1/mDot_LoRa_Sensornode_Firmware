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

#ifndef APP_TASKTESLA_H_
#define APP_TASKTESLA_H_

/**
 * @class TaskTesla
 * @brief This TaskTesla Class handles the tesla measurement using the MPU9250.
 * Starting the task using the start() starts the measurement of all axis.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskTesla {
public:
	TaskTesla(MPU9250*,Mutex*, Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*);
	TaskTesla(MPU9250*,Mutex*,Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskTesla();


	/**
	 * @brief Starts the task by building it and connecting a callback function to
	 * the mbed::Thread
	 * @return
	 */
	osStatus start();

	/**
	 * @brief Stops the task. Should only be used after start() was used
	 * @return
	 */
	osStatus stop();


	/**
	 * @brief Gets the actual state of the Task either RUNNING or SLEEPING
	 * @return
	 */
	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	MPU9250* mpu9250;


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
	 * @brief A thread safe method that measures Teslas of each axis. After the measurement
	 * it stores the data inside a MPU9250TelsaMessage
	 */
	void measureTesla();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueTesla the queue where the MPU9250TeslaMessage will be stored
	 */
	void setQueue(Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>*queueTesla);

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

#endif /* APP_TASKTESLA_H_ */
