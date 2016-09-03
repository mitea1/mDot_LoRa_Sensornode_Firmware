/**
 * @file TaksHumidity.h
 *
 * @author Adrian
 * @date 30.05.2016
 *

 */
#include "BME280.h"
#include "BME280HumidityMessage.h"
#include "main.h"

#ifndef TASKHUMIDITY_H_
#define TASKHUMIDITY_H_

/**
 * @class TaskHumidity
 * @brief This TaskHumidity Class handles the humidity measurement using the BME280.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskHumidity {

public:
	TaskHumidity(BME280*,Mutex*, Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>*);
	TaskHumidity(BME280*,Mutex*,Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskHumidity();


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
	rtos::Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	BME280* bme280;
	BME280_MODE bme280Mode;


	/**
	 * @brief A Callback function thats called by the mbed::Thread of this TaskClass
	 * @param
	 */
	static void callBack(void const *);

	/**
	 * @brief A thread safe method that measures the humidity. After measuring the humidity
	 * it stores the humidity value inside a BME280HumidityMessage
	 */
	void measureHumidity();

	/**
	 * @brief Attaches the idle_hook for this task
	 * @param
	 */
	void attachIdleHook(void (*fptr) (void));

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueHumidity the queue where the BME280Humidity will be stored
	 */
	void setQueue(Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queueHumdity);

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
	void setState(TASK_STATE);
};


#endif /* TASKHUMIDITY_H_ */
