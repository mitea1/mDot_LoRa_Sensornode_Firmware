/**
 * @file TaskGPS.h
 *
 * @author Adrian
 * @date 30.05.2016
 *
 */
#include "uBlox.h"
#include "UBloxGPSMessage.h"
#include "main.h"

#ifndef TASKGPS_H_
#define TASKGPS_H_

/**
 * @class TaskGPS
 * @brief This TaskGPS Class handles the GPS measurement using the uBlox.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskGPS {
public:
	TaskGPS(uBlox*,Mutex*, Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>*);
	TaskGPS(uBlox*,Mutex*,Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskGPS();


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
	rtos::Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexUART ;
	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	uBlox* mUBlox;
	uBLOX_MODE uBloxMode;


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
	 * @brief A thread safe method that acquires GPS values. After acquiring GPS Data
	 *  it stores the data inside a uBLoxGPSMessage
	 */
	void measureGps();


	/**
	 * @brief Sets the message Queue of the Task where the acquired data will be stored
	 * after the acquisition
	 * @param queueGps the queue where the MPU9250AccelerationMessage will be stored
	 */
	void setQueue(Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queueGps);

	/**
	 * @brief Sets the mutex thats used for a thread safe acquisition
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

#endif /* TASKGPS_H_ */
