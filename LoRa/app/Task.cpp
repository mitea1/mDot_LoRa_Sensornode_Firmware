/*
 * Task.cpp
 *
 *  Created on: Sep 9, 2016
 *      Author: Adrian
 */

#include "Task.h"

Task::Task() {
	// TODO Auto-generated constructor stub

}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

osStatus Task::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus Task::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void Task::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const Task* constInstance = static_cast<const Task* >(data);
	Task* instance = const_cast<Task*>(constInstance);

	instance->measure();
}

void Task::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void Task::setMutex(Mutex* mutex){
	this->mutexInterface = mutex;
}

void Task::setPriority(osPriority priority){
	this->priority = priority;
}

void Task::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void Task::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void Task::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE Task::getState(){
	return state;
}

