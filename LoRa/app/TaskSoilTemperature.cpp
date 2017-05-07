/*
 * TaskSoilMeasurement.cpp
 *
 *  Created on: 09.01.2017
 *      Author: Adrian
 */

#include "TaskSoilTemperature.h"

TaskSoilTemperature::TaskSoilTemperature(
		SHTx::SHT15* sht15, Mutex* mutexI2C,
		Queue<SHT15SoilTemperatureMessage,SOIL_TEMPERATURE_QUEUE_LENGHT>* queue){
	this->sht15 = sht15;
	setMutex(mutexI2C);
	setQueue(queue);
}

TaskSoilTemperature::TaskSoilTemperature(
		SHTx::SHT15* sht15, Mutex* mutexI2C,
		Queue<SHT15SoilTemperatureMessage,SOIL_TEMPERATURE_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char* stackPointer){
	this->sht15 = sht15;
	setMutex(mutexI2C);
	setQueue(queue);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskSoilTemperature::~TaskSoilTemperature() {
	// TODO Auto-generated destructor stub
}

void TaskSoilTemperature::measure(){
	SHT15SoilTemperatureMessage sht15SoilTemperatureMessage;


	while(true){
		mutexInterface->lock(osWaitForever);
		sht15->reset();
		sht15->update();
		sht15->setScale(false);
		sht15SoilTemperatureMessage.setSoilTemperature(sht15->getTemperature());
		mutexInterface->unlock();

		queue->put(&sht15SoilTemperatureMessage,osWaitForever);
		osDelay(SOIL_TEMPERATURE_TASK_DELAY_MS);
	}
}

void TaskSoilTemperature::setQueue(Queue<SHT15SoilTemperatureMessage,SOIL_TEMPERATURE_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

