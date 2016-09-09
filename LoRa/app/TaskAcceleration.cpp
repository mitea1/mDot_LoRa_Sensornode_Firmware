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


void TaskAcceleration::measure(){
	MPU9250AccelerationMessage mpu9250AccelerationMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		mpu9250AccelerationMessage.setXAcceleration(mpu9250->getXAxisAcceleration());
		mpu9250AccelerationMessage.setYAcceleration(mpu9250->getYAxisAcceleration());
		mpu9250AccelerationMessage.setZAcceleration(mpu9250->getZAxisAcceleration());
		mutexInterface->unlock();

		queue->put(&mpu9250AccelerationMessage,osWaitForever);
		osDelay(ACCELERATION_TASK_DELAY_MS);
	}


}

/**
 * @brief Sets the message Queue of the Task where the measured values will be stored
 * after the measurement
 * @param queueAcceleration the queue where the MPU9250AccelerationMessage will be stored
 */
void TaskAcceleration::setQueue(Queue<MPU9250AccelerationMessage,ACCELERATION_QUEUE_LENGHT>* queue){
	this->queue = queue;

}


