/*
 * TaskProximity.cpp
 *
 *  Created on: Jun 3, 2016
 *      Author: Adrian
 */

#include "TaskProximity.h"

TaskProximity::TaskProximity(SI1143* si1143,Mutex* mutexI2C, Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queue){
	this->si1143 = si1143;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskProximity::TaskProximity(SI1143* si1143,rtos::Mutex* mutexI2C,
	rtos::Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskProximity(si1143,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskProximity::~TaskProximity() {
	// TODO Auto-generated destructor stub
}

osStatus TaskProximity::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskProximity::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void TaskProximity::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskProximity* constInstance = static_cast<const TaskProximity* >(data);
	TaskProximity* instance = const_cast<TaskProximity*>(constInstance);

	instance->measureProximity();
}

void TaskProximity::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void TaskProximity::measureProximity(){
	SI1143ProximityMessage si1143ProximityMessage;

	while(true){
		mutexI2C->lock(osWaitForever);
		si1143ProximityMessage.setProximity(si1143->getProximity(1));
		mutexI2C->unlock();

		queue->put(&si1143ProximityMessage,osWaitForever);
		osDelay(PROXIMITY_TASK_DELAY_MS);
	}
}

void TaskProximity::setQueue(Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskProximity::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskProximity::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskProximity::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskProximity::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskProximity::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE TaskProximity::getState(){
	return state;
}
