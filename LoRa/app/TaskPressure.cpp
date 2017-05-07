/*
 * TaskPressure.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskPressure.h"

TaskPressure::TaskPressure(BME280* bme280,Mutex* mutexI2C, Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue){
	this->bme280 = bme280;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskPressure::TaskPressure(BME280* bme280,rtos::Mutex* mutexI2C,
	rtos::Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer){
	this->bme280 = bme280;
	setMutex(mutexI2C);
	setQueue(queue);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskPressure::~TaskPressure() {
	// TODO Auto-generated destructor stub
}

void TaskPressure::measure(){
	BME280PressureMessage bme280PressureMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		bme280PressureMessage.setPressure(bme280->getPressureFloat());
		mutexInterface->unlock();

		queue->put(&bme280PressureMessage,osWaitForever);
		osDelay(PRESSURE_TASK_DELAY_MS);
	}

}

void TaskPressure::setQueue(Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue){
	this->queue = queue;
}
