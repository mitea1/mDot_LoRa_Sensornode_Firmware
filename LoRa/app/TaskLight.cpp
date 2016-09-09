/*
 * TaskLight.cpp
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#include "TaskLight.h"

TaskLight::TaskLight(MAX44009* max44009,Mutex* mutexI2C, Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue){
	this->max44009 = max44009;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskLight::TaskLight(MAX44009* max44009,rtos::Mutex* mutexI2C,
		rtos::Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskLight(max44009,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskLight::~TaskLight() {
	// TODO Auto-generated destructor stub
}

void TaskLight::measure(){
	MAX44009Message* max44009Message = new MAX44009Message();

	while(true){
		mutexInterface->lock(osWaitForever);
		max44009Message->setLux(max44009->getLux());
		mutexInterface->unlock();

		queue->put(max44009Message,osWaitForever);
		osDelay(LIGHT_TASK_DELAY_MS);
	}

}

void TaskLight::setQueue(Queue<MAX44009Message,LIGHT_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

