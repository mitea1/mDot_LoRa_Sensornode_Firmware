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

#ifndef TASKTEMPERATURE_H_
#define TASKTEMPERATURE_H_

/**
 * @class TaskTemperature
 * @brief This TaskTemperature Class handles the temperature measurement using the BME280.
 * Starting the task using the start() starts the measurement of all axis.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskTemperature {
public:
	TaskTemperature(BME280*,Mutex*, Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>*);
	TaskTemperature(BME280*,Mutex*,Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskTemperature();


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
	rtos::Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	BME280* bme280;


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
	 * @brief A thread safe method that measures the temperature. After measuring
	 * the temperature it stores the data inside a BME280TemperatureMessage
	 */
	void measureTemperature();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueGyro the queue where the MPU9250GyroscopeMessage will be stored
	 */
	void setQueue(Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queueTemperature);

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

#endif /* TASKTEMPERATURE_H_ */
