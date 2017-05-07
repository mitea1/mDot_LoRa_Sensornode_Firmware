/*
 * TaskHumidity.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskHumidity.h"

TaskHumidity::TaskHumidity(BME280* bme280,Mutex* mutexI2C, Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue){
	this->bme280 = bme280;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskHumidity::TaskHumidity(BME280* bme280,rtos::Mutex* mutexI2C,
		rtos::Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer){
	this->bme280 = bme280;
	setMutex(mutexI2C);
	setQueue(queue);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskHumidity::~TaskHumidity() {
	// TODO Auto-generated destructor stub
}

void TaskHumidity::measure(){
	BME280HumidityMessage bme280HumidityMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		bme280HumidityMessage.setHumidity(bme280->getHumidityFloat());
		mutexInterface->unlock();

		queue->put(&bme280HumidityMessage,osWaitForever);
		osDelay(HUMIDITY_TASK_DELAY_MS);
	}


}

void TaskHumidity::setQueue(Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue){
	this->queue = queue;
}
