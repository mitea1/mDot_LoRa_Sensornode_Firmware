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
#include "Task.h"

#ifndef APP_TASKLORAMEASUREMENT_H_
#define APP_TASKLORAMEASUREMENT_H_

/**
 * @class
 */
class TaskLoRaMeasurement : public Task {
public:
	TaskLoRaMeasurement(LoRa*,Mutex*, Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*);
	TaskLoRaMeasurement(LoRa*,Mutex*,Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskLoRaMeasurement();

private:
	rtos::Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>* queue;
	LoRa* lora;


	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueSingal the queue where the LoRa Signal strength will be stored
	 */
	void setQueue(Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>*);

};

#endif /* APP_TASKLORAMEASUREMENT_H_ */
