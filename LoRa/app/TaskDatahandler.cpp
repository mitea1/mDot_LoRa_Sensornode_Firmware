/*
 * TaskDatahandler.cpp
 *
 *  Created on: May 27, 2016
 *      Author: Adrian
 */

#include "TaskDatahandler.h"
#include "LoRaMessageBuilder.h"

TaskDatahandler::TaskDatahandler(LoRa* lora,Mutex* mutexLora, QueueBundle queueBundle,
		osPriority priority,uint32_t stackSize, unsigned char* stackPointer){
	setLoRa(lora);
	setMutex(mutexLora);
	setQueueBundle(queueBundle);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskDatahandler::~TaskDatahandler() {
	// TODO Auto-generated destructor stub
}

osStatus TaskDatahandler::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
	attachIdleHook(NULL);
}

osStatus TaskDatahandler::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void TaskDatahandler::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskDatahandler* constInstance = static_cast<const TaskDatahandler* >(data);
	TaskDatahandler* instance = const_cast<TaskDatahandler*>(constInstance);

	instance->handleData();
}

void TaskDatahandler::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void TaskDatahandler::handleData(){

	while(true){
		getMessagesFromSensorQueues();
		forwardSensorMessages();
		osDelay(std::max((uint32_t)DATAHANLDER_TASK_DELAY_MS,(uint32_t)lora->getNextTxMs()));
	}
}

void TaskDatahandler::getMessagesFromSensorQueues(){
	lightMeasureEvent = queueBundle.queueLight->get(0);
	temperatureMeasureEvent = queueBundle.queueTemperature->get(0);
	pressureMeasureEvent = queueBundle.queuePressure->get(0);
	humidityMeasureEvent = queueBundle.queueHumidity->get(0);
	accelerationMeasureEvent = queueBundle.queueAcceleration->get(0);
	gyroscopeMeasureEvent = queueBundle.queueGyro->get(0);
	teslaMeasureEvent = queueBundle.queueTesla->get(0);
	proximityMeasureEvent = queueBundle.queueProximity->get(0);
	gpsMeasureEvent = queueBundle.queueGps->get(0);
	soilTemperatureMeasureEvent = queueBundle.queueSoilTemperature->get(0);
	soilMoistureMeasureEvent = queueBundle.queueSoilMoisture->get(0);
	loraMeasureEvent = queueBundle.queueLoRaMeasurments->get(0);
	powerMeasureEvent = queueBundle.queuePowerMeasurments->get(0);
}

void TaskDatahandler::forwardSensorMessages(){
	std::string loraMessage;
	std::vector<uint8_t> dataToSend;
	std::vector<uint8_t> dataReceived;

	LoRaMessageBuilder* loraMessageBuilder = new LoRaMessageBuilder();

	debugSerial->printf("\n");

	if (lightMeasureEvent.status == osEventMessage) {
		loraMessageBuilder->appendLoRaMessage(lightMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	if (temperatureMeasureEvent.status == osEventMessage) {
		loraMessageBuilder->appendLoRaMessage(temperatureMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	if (pressureMeasureEvent.status == osEventMessage) {
		loraMessageBuilder->appendLoRaMessage(pressureMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}
	
	if (humidityMeasureEvent.status == osEventMessage) {
		loraMessageBuilder->appendLoRaMessage(humidityMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}
	
	if (accelerationMeasureEvent.status == osEventMessage) {
		loraMessageBuilder->appendLoRaMessage(accelerationMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}
	
	if (gyroscopeMeasureEvent.status == osEventMessage) {
		loraMessageBuilder->appendLoRaMessage(gyroscopeMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	if (teslaMeasureEvent.status == osEventMessage) {
		loraMessageBuilder->appendLoRaMessage(teslaMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	if(proximityMeasureEvent.status == osEventMessage){
		loraMessageBuilder->appendLoRaMessage(proximityMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	if(gpsMeasureEvent.status == osEventMessage){
		loraMessageBuilder->appendLoRaMessage(gpsMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	if(soilTemperatureMeasureEvent.status == osEventMessage){
		loraMessageBuilder->appendLoRaMessage(soilTemperatureMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	if(soilMoistureMeasureEvent.status == osEventMessage){
			loraMessageBuilder->appendLoRaMessage(soilMoistureMeasureEvent.value.p);
			debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	if(loraMeasureEvent.status == osEventMessage){
		loraMessageBuilder->appendLoRaMessage(loraMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}
	
	if(powerMeasureEvent.status == osEventMessage){
		loraMessageBuilder->appendLoRaMessage(powerMeasureEvent.value.p);
		debugSerial->printf("%s\n",loraMessageBuilder->getSensorMessage()->getLoRaMessageString());
	}

	debugSerial->printf("\n");

	// format data for sending to the gateway
	for (std::string::iterator it = loraMessageBuilder->getMessageAscii()->begin(); it != loraMessageBuilder->getMessageAscii()->end(); it++){
		dataToSend.push_back((uint8_t) *it);
	}

	loraMessageBuilder->getMessageAscii()->clear();

	mutexLora->lock(osWaitForever);
	lora->send(dataToSend);
	lora->recv(dataReceived);
	mutexLora->unlock();

	if(!dataReceived.empty()){
		commandMessage.setCommandString(dataReceived);
		commandMessage.setCommandHex(dataReceived.at(0));
		queueBundle.queueCommands->put(&commandMessage,osWaitForever);
	}

	dataToSend.clear();
	dataReceived.clear();

}

void TaskDatahandler::setMutex(Mutex* mutexLora){
	this->mutexLora = mutexLora;
}

void TaskDatahandler::setQueueBundle(QueueBundle queueBundle){
	this->queueBundle = queueBundle;
}

void TaskDatahandler::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskDatahandler::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskDatahandler::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskDatahandler::setDebugSerial(RawSerial* debugSerial){
	this->debugSerial = debugSerial;
}

void TaskDatahandler::setLoRa(LoRa* lora){
	this->lora = lora;
}

void TaskDatahandler::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE TaskDatahandler::getState(){
	return state;
}





