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

osStatus TaskTemperature::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskTemperature::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void TaskTemperature::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskTemperature* constInstance = static_cast<const TaskTemperature* >(data);
	TaskTemperature* instance = const_cast<TaskTemperature*>(constInstance);

	instance->measureTemperature();
}

void TaskTemperature::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void TaskTemperature::measureTemperature(){
	BME280TemperatureMessage bme280TemperatureMessage;

	while(true){
		mutexI2C->lock(osWaitForever);
		bme280TemperatureMessage.setTemperature(bme280->getTemperatureFloat());
		mutexI2C->unlock();

		queue->put(&bme280TemperatureMessage,osWaitForever);
		osDelay(TEMPERATURE_TASK_DELAY_MS);
	}


}

void TaskTemperature::setQueue(Queue<BME280TemperatureMessage,TEMPERATURE_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskTemperature::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskTemperature::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskTemperature::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskTemperature::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskTemperature::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE TaskTemperature::getState(){
	return state;
}

