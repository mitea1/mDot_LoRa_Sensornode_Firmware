/*
 * TaskGPS.cpp
 *
 *  Created on: May 30, 2016
 *      Author: Adrian
 */

#include "TaskGPS.h"

TaskGPS::TaskGPS(uBlox* uBlox,Mutex* mutexUART, Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue){
	this->mUBlox = uBlox;
	setMutex(mutexUART);
	setQueue(queue);
}

TaskGPS::TaskGPS(uBlox* uBlox,rtos::Mutex* mutexUART,
		rtos::Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskGPS(uBlox,mutexUART,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskGPS::~TaskGPS() {
	// TODO Auto-generated destructor stub
}

void TaskGPS::measure(){
	UBloxGPSMessage uBloxGPSMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		uBloxGPSMessage.setLongitude(mUBlox->getLongitude());
		uBloxGPSMessage.setLatitude(mUBlox->getLatitude());
		mutexInterface->unlock();

		queue->put(&uBloxGPSMessage,osWaitForever);
		osDelay(GPS_TASK_DELAY_MS);
	}


}

void TaskGPS::setQueue(Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue){
	this->queue = queue;
}
