/*
 * TaskAcceleration.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskAcceleration.h"

TaskAcceleration::TaskAcceleration(MPU9250* mpu9250,Mutex* mutexI2C, Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queue){
	this->mpu9250 = mpu9250;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskAcceleration::TaskAcceleration(MPU9250* mpu9250,rtos::Mutex* mutexI2C,
	rtos::Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskAcceleration(mpu9250,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskAcceleration::~TaskAcceleration() {
	// TODO Auto-generated destructor stub
}

osStatus TaskAcceleration::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskAcceleration::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void TaskAcceleration::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskAcceleration* constInstance = static_cast<const TaskAcceleration* >(data);
	TaskAcceleration* instance = const_cast<TaskAcceleration*>(constInstance);

	instance->measureAcceleration();
}

void TaskAcceleration::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void TaskAcceleration::measureAcceleration(){
	MPU9250AccelerationMessage mpu9250AccelerationMessage;

	while(true){
		mutexI2C->lock(osWaitForever);
		mpu9250AccelerationMessage.setXAcceleration(mpu9250->getXAxisAcceleration());
		mpu9250AccelerationMessage.setYAcceleration(mpu9250->getYAxisAcceleration());
		mpu9250AccelerationMessage.setZAcceleration(mpu9250->getZAxisAcceleration());
		mutexI2C->unlock();

		queue->put(&mpu9250AccelerationMessage,osWaitForever);
		osDelay(ACCELERATION_TASK_DELAY_MS);
	}


}

void TaskAcceleration::setQueue(Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskAcceleration::setMutex(Mutex* mutex){
	this->mutexI2C = mutex;
}

void TaskAcceleration::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskAcceleration::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskAcceleration::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskAcceleration::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE TaskAcceleration::getState(){
	return state;
}

