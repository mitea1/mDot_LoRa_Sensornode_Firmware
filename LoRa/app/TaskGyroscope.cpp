/*
 * TaskGyroscope.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskGyroscope.h"

TaskGyroscope::TaskGyroscope(MPU9250* mpu9250,Mutex* mutexI2C, Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queue){
	this->mpu9250 = mpu9250;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskGyroscope::TaskGyroscope(MPU9250* mpu9250,rtos::Mutex* mutexI2C,
	rtos::Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queue,
	osPriority priority, uint32_t stackSize, unsigned char *stackPointer){
	this->mpu9250 = mpu9250;
	setMutex(mutexI2C);
	setQueue(queue);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskGyroscope::~TaskGyroscope() {
	// TODO Auto-generated destructor stub
}

void TaskGyroscope::measure(){
	MPU9250GyroscopeMessage mpu9250GyroscopeMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		mpu9250GyroscopeMessage.setXGyro(mpu9250->getXAxisGyro());
		mpu9250GyroscopeMessage.setYGyro(mpu9250->getYAxisGyro());
		mpu9250GyroscopeMessage.setZGyro(mpu9250->getZAxisGyro());
		mutexInterface->unlock();

		queue->put(&mpu9250GyroscopeMessage,osWaitForever);
		osDelay(GYROSCOPE_TASK_DELAY_MS);
	}


}

void TaskGyroscope::setQueue(Queue<MPU9250GyroscopeMessage,GYROSCOPE_QUEUE_LENGHT>* queue){
	this->queue = queue;
}
