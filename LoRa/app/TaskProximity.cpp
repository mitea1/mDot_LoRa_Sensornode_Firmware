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

void TaskProximity::measure(){
	SI1143ProximityMessage si1143ProximityMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		si1143ProximityMessage.setProximity(si1143->getProximity(1));
		mutexInterface->unlock();

		queue->put(&si1143ProximityMessage,osWaitForever);
		osDelay(PROXIMITY_TASK_DELAY_MS);
	}
}

void TaskProximity::setQueue(Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queue){
	this->queue = queue;
}
