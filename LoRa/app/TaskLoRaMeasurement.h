/**
 * @file TaskLoRaMeasurement.h
 *
 * @author Adrian
 * @date 13.06.2016
 */

#include <Thread.h>
#include <Queue.h>
#include <Mutex.h>
#include "LoRa.h"
#include "LoRaMeasuermentMessage.h"
#include "main.h"

#ifndef APP_TASKLORAMEASUREMENT_H_
#define APP_TASKLORAMEASUREMENT_H_

class TaskLoRaMeasurement {
public:
	TaskLoRaMeasurement(LoRa*,Mutex*, Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*);
	TaskLoRaMeasurement(LoRa*,Mutex*,Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskLoRaMeasurement();

	osStatus start();
	osStatus stop();

	TASK_STATE getState();

private:
	rtos::Thread* thread;
	rtos::Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>* queue;
	rtos::Mutex* mutexLoRa ;
	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	LoRa* lora;

	static void callBack(void const *);

	/**
	 * @brief Attaches the idle_hook for this task
	 * @param
	 */
	void attachIdleHook(void (*fptr) (void));

	void measureSignal();

	void setQueue(Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*);
	void setMutex(Mutex*);
	void setPriority(osPriority);
	void setStackSize(uint32_t);
	void setStackPointer(unsigned char*);

	void setState(TASK_STATE);

};

#endif /* APP_TASKLORAMEASUREMENT_H_ */
