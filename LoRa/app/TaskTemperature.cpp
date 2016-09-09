/*
 * TaskTemperature.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskTemperature.h"

TaskTemperature::TaskTemperature(BME280* bme280,Mutex* mutexI2C, Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queue){
	this->bme280 = bme280;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskTemperature::TaskTemperature(BME280* bme280,rtos::Mutex* mutexI2C,
	rtos::Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskTemperature(bme280,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskTemperature::~TaskTemperature() {
	// TODO Auto-generated destructor stub
}

void TaskTemperature::measure(){
	BME280TemperatureMessage bme280TemperatureMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		bme280TemperatureMessage.setTemperature(bme280->getTemperatureFloat());
		mutexInterface->unlock();

		queue->put(&bme280TemperatureMessage,osWaitForever);
		osDelay(TEMPERATURE_TASK_DELAY_MS);
	}


}

void TaskTemperature::setQueue(Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queue){
	this->queue = queue;
}
