/*
 * TaskCommandHandler.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: Adrian
 */

#include "TaskCommandHandler.h"

TaskCommandHandler::TaskCommandHandler(Queue<CommandMessage,COMMAND_QUEUE_LENGHT>* queue,
		osPriority priority, uint32_t stackSize, unsigned char* stackPointer){
	setQueue(queue);
	setPriority(priority);
	setStackSize(stackSize);
	setStackPointer(stackPointer);
	setState(SLEEPING);
}

TaskCommandHandler::~TaskCommandHandler() {
	// TODO Auto-generated destructor stub
}

osStatus TaskCommandHandler::start(){
	setState(RUNNING);
	this->thread = new rtos::Thread(callBack,this);
	attachIdleHook(NULL);
}

osStatus TaskCommandHandler::stop(){
	thread->terminate();
	setState(SLEEPING);
	delete this->thread;
}

void TaskCommandHandler::callBack(void const* data){
	// WOODHAMMER METHOD of Casting!
	const TaskCommandHandler* constInstance = static_cast<const TaskCommandHandler* >(data);
	TaskCommandHandler* instance = const_cast<TaskCommandHandler*>(constInstance);

	instance->handleCommands();
}

void TaskCommandHandler::attachIdleHook(void (*fptr) (void)){
	this->thread->attach_idle_hook(fptr);
}

void TaskCommandHandler::handleCommands(){

	while(true){
		getCommandMessages();
		processCommands();
		osDelay(COMMANDHANLDER_TASK_DELAY_MS);
	}
}

void TaskCommandHandler::getCommandMessages(){
	commandReceiveEvent = queue->get(0);
}

void TaskCommandHandler::processCommands(){

	debugSerial->printf("\n");
	if (commandReceiveEvent.status == osEventMessage) {

		CommandMessage* commandMessage = (CommandMessage*) commandReceiveEvent.value.p;
//		 Do your own stuff according to the received command
//		 For example turn on LED if 0x00 was sent or turn it off if 0x01 was sent
//		DigitalOut* pinD6 = new DigitalOut(PA_1);
//
//		switch(commandMessage->getCommandHex()){
//
//		case LORA_COMMAND_ACTION_0:
//			pinD6->write(0);
//			break;
//
//		case LORA_COMMAND_ACTION_1:
//			pinD6->write(1);
//			break;
//
//		}

		debugSerial->printf("Received Command: %s\n",commandMessage->getCommandString().c_str());

	}

}

void TaskCommandHandler::setQueue(Queue<CommandMessage,COMMAND_QUEUE_LENGHT>* queueCommand){
	this->queue = queueCommand;
}

void TaskCommandHandler::setPriority(osPriority priority){
	this->priority = priority;
}

void TaskCommandHandler::setStackSize(uint32_t stacksize){
	this->stack_size = stacksize;
}

void TaskCommandHandler::setStackPointer(unsigned char* stackPointer){
	this->stack_pointer = stackPointer;
}

void TaskCommandHandler::setDebugSerial(RawSerial* debugSerial){
	this->debugSerial = debugSerial;
}

void TaskCommandHandler::setState(TASK_STATE state){
	this->state = state;
}

TASK_STATE TaskCommandHandler::getState(){
	return state;
}






