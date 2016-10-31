/*
 * TaskPowerMeasurment.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Adrian
 */
#include "INA219.h"
#include "PowerMeasurmentMessage.h"
#include "main.h"
#include "Task.h"
#ifndef TASKPOWERMEASURMENT_H_
#define TASKPOWERMEASURMENT_H_

class TaskPowerMeasurement : public Task {
public:
	TaskPowerMeasurement(INA219*,Mutex*, Queue<PowerMeasurementMessage,POWER_MEASUREMENT_QUEUE_LENGHT>*);
	TaskPowerMeasurement(INA219*,Mutex*,Queue<PowerMeasurementMessage,POWER_MEASUREMENT_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskPowerMeasurement();

private:
	rtos::Queue<PowerMeasurementMessage,POWER_MEASUREMENT_QUEUE_LENGHT>* queue;

	INA219* ina219;

	void measure();

	void setQueue(Queue<PowerMeasurementMessage,POWER_MEASUREMENT_QUEUE_LENGHT>* queuePowerMeasurment);
};


#endif /* TASKPOWERMEASURMENT_H_ */
