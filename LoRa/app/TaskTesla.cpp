/*
 * TaskTesla.cpp
 *
 *  Created on: 01.06.2016
 *      Author: Adrian
 */

#include "TaskTesla.h"

TaskTesla::TaskTesla(MPU9250* mpu9250,Mutex* mutexI2C, Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue){
	this->mpu9250 = mpu9250;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskTesla::TaskTesla(MPU9250* mpu9250,rtos::Mutex* mutexI2C,
	rtos::Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskTesla(mpu9250,mutexI2C,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskTesla::~TaskTesla() {
	// TODO Auto-generated destructor stub
}

void TaskTesla::measure(){
	MPU9250TeslaMessage mpu9250TeslaMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		mpu9250TeslaMessage.setXTesla(mpu9250->getXAxisTesla());
		mpu9250TeslaMessage.setYTesla(mpu9250->getYAxisTesla());
		mpu9250TeslaMessage.setZTesla(mpu9250->getZAxisTesla());
		mutexInterface->unlock();

		queue->put(&mpu9250TeslaMessage,osWaitForever);
		osDelay(TESLA_TASK_DELAY_MS);
	}
}

void TaskTesla::setQueue(Queue<MPU9250TeslaMessage,TESLA_QUEUE_LENGHT>* queue){
	this->queue = queue;
}
