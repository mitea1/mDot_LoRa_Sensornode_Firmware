/*
 * TaskPowerMeasurment.cpp
 *
 *  Created on: Oct 31, 2016
 *      Author: Adrian
 */

#include "TaskPowerMeasurement.h"

TaskPowerMeasurement::TaskPowerMeasurement(INA219* ina219,Mutex* mutex, Queue<PowerMeasurementMessage,POWER_MEASUREMENT_QUEUE_LENGHT>* queue) {
	this->ina219 = ina219;
	setMutex(mutex);
	setQueue(queue);
}

TaskPowerMeasurement::TaskPowerMeasurement(INA219* ina219,Mutex* mutex, Queue<PowerMeasurementMessage,POWER_MEASUREMENT_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char* stackPointer) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskPowerMeasurement::~TaskPowerMeasurement(){
	// TODO Auto-generated destructor stub
}

void TaskPowerMeasurement::measure(){
	PowerMeasurementMessage powerMeasurmentMessage;

	while(true){
		mutexInterface->lock(osWaitForever);
		powerMeasurmentMessage.setShuntVoltage(ina219->getShuntVoltage_mV());
		powerMeasurmentMessage.setBusVoltage(ina219->getBusVoltage_V());
		powerMeasurmentMessage.setCurrent(ina219->getCurrent_mA());
		powerMeasurmentMessage.setPower(ina219->getPower_mW());
		mutexInterface->unlock();

		queue->put(&powerMeasurmentMessage,osWaitForever);
		osDelay(POWER_MEASUREMENT_TASK_DELAY_MS);
	}

}

void TaskPowerMeasurement::setQueue(Queue<PowerMeasurementMessage,POWER_MEASUREMENT_QUEUE_LENGHT>* queue){
	this->queue = queue;

}
