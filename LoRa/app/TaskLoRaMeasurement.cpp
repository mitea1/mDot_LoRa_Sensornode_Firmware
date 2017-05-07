/**
 * @file TaskLoRaMeasurement.cpp
 *
 * @author Adrian
 * @date 13.06.2016
 */

#include "TaskLoRaMeasurement.h"

TaskLoRaMeasurement::TaskLoRaMeasurement(LoRa* lora,Mutex* mutexLoRa,
		Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>* queue){
	this->lora = lora;
	setMutex(mutexLoRa);
	setQueue(queue);
}

TaskLoRaMeasurement::TaskLoRaMeasurement(LoRa* lora,Mutex* mutexLoRa,
		rtos::Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer){
	this->lora = lora;
	setMutex(mutexLoRa);
	setQueue(queue);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskLoRaMeasurement::~TaskLoRaMeasurement() {
	// TODO Auto-generated destructor stub
}

void TaskLoRaMeasurement::measure(){
	LoRaMeasurementMessage* loraMeasurementMessage = new LoRaMeasurementMessage();

	while(true){
		mutexInterface->lock(osWaitForever);
		loraMeasurementMessage->setRssi(lora->getLastRssi());
		loraMeasurementMessage->setSnr(lora->getLastSnr());
		loraMeasurementMessage->setSpreadingFactor(lora->getSpreadingFactor());
		loraMeasurementMessage->setTxPowerdBm(lora->getTxPowerdBm());
		mutexInterface->unlock();

		queue->put(loraMeasurementMessage,osWaitForever);
		osDelay(LORA_MEASUREMENT_TASK_DELAY_MS);
	}


}

void TaskLoRaMeasurement::setQueue(Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>* queue){
	this->queue = queue;
}
