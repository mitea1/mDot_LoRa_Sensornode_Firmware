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
		osPriority priority, uint32_t stackSize, unsigned char *stackPointer):TaskLoRaMeasurement(lora,mutexLoRa,queue) {
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskLoRaMeasurement::~TaskLoRaMeasurement() {
	// TODO Auto-generated destructor stub
}

osStatus TaskLoRaMeasurement::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
}

osStatus TaskLoRaMeasurement::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void TaskLoRaMeasurement::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskLoRaMeasurement* constInstance = static_cast<const TaskLoRaMeasurement* >(data);
	TaskLoRaMeasurement* instance = const_cast<TaskLoRaMeasurement*>(constInstance);

	instance->measureSignal();
}

void TaskLoRaMeasurement::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void TaskLoRaMeasurement::measureSignal(){
	LoRaMeasurementMessage* loraMeasurementMessage = new LoRaMeasurementMessage();

	while(true){
		mutexLoRa->lock(osWaitForever);
		loraMeasurementMessage->setRssi(lora->getLastRssi());
		loraMeasurementMessage->setSnr(lora->getLastSnr());
		loraMeasurementMessage->setSpreadingFactor(lora->getSpreadingFactor());
		loraMeasurementMessage->setTxPowerdBm(lora->getTxPowerdBm());
		mutexLoRa->unlock();

		queue->put(loraMeasurementMessage,osWaitForever);
		osDelay(LORA_MEASUREMENT_TASK_DELAY_MS);
	}


}

void TaskLoRaMeasurement::setQueue(Queue<LoRaMeasurementMessage,LORA_MEASUREMENT_QUEUE_LENGHT>* queue){
	this->queue = queue;
}

void TaskLoRaMeasurement::setMutex(Mutex* mutex){
	this->mutexLoRa = mutex;
}

void TaskLoRaMeasurement::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskLoRaMeasurement::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskLoRaMeasurement::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskLoRaMeasurement::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE TaskLoRaMeasurement::getState(){
	return state;
}

