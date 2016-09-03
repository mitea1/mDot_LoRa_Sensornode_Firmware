/**
 * @file TaskProximity.h
 *
 * @author Adrian
 * @date 03.06.2016
 *
 */
#include "SI1143.h"
#include "SI1143ProximityMessage.h"
#include "main.h"

#ifndef TASKPROXIMITY_H_
#define TASKPROXIMITY_H_

/**
 * @class TaskProximity
 * @brief This TaskProximity Class handles the proximity measurement using the SI1143.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskProximity {
public:
	TaskProximity(SI1143*,Mutex*,Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>*);
	TaskProximity(SI1143*,Mutex*,Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskProximity();


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
	rtos::Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexI2C ;
	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	SI1143* si1143;


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
	 * @brief A thread safe method that acquires data from the gyroscope. After acquiring data from the
	 * it stores the data inside a MPU9250GyroscopeMessage
	 */
	void measureProximity();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueProximity the queue where the SI1143ProximityMessage will be stored
	 */
	void setQueue(Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queueProximity);

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

#endif /* TASKPROXIMITY_H_ */
