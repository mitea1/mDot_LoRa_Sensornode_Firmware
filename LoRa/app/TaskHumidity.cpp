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
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskHumidity(bme280,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskHumidity::~TaskHumidity() {
	// TODO Auto-generated destructor stub
}

osStatus TaskHumidity::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskHumidity::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void TaskHumidity::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskHumidity* constInstance = static_cast<const TaskHumidity* >(data);
	TaskHumidity* instance = const_cast<TaskHumidity*>(constInstance);

	instance->measureHumidity();
}

void TaskHumidity::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void TaskHumidity::measureHumidity(){
	BME280HumidityMessage bme280HumidityMessage;

	while(true){
		mutexI2C->lock(osWaitForever);
		bme280HumidityMessage.setHumidity(bme280->getHumidityFloat());
		mutexI2C->unlock();

		queue->put(&bme280HumidityMessage,osWaitForever);
		osDelay(HUMIDITY_TASK_DELAY_MS);
	}


}

void TaskHumidity::setQueue(Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskHumidity::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskHumidity::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskHumidity::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskHumidity::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskHumidity::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE TaskHumidity::getState(){
	return state;
}

