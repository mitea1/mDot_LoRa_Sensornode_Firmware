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
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskPressure(bme280,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskPressure::~TaskPressure() {
	// TODO Auto-generated destructor stub
}

osStatus TaskPressure::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskPressure::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void TaskPressure::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskPressure* constInstance = static_cast<const TaskPressure* >(data);
	TaskPressure* instance = const_cast<TaskPressure*>(constInstance);

	instance->measurePressure();
}

void TaskPressure::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void TaskPressure::measurePressure(){
	BME280PressureMessage bme280PressureMessage;

	while(true){
		mutexI2C->lock(osWaitForever);
		bme280PressureMessage.setPressure(bme280->getPressureFloat());
		mutexI2C->unlock();

		queue->put(&bme280PressureMessage,osWaitForever);
		osDelay(PRESSURE_TASK_DELAY_MS);
	}

}

void TaskPressure::setQueue(Queue<BME280PressureMessage,PRESSURE_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskPressure::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskPressure::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskPressure::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskPressure::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskPressure::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE TaskPressure::getState(){
	return state;
}

