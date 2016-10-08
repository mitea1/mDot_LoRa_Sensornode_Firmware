/*
 * CommandMessage.cpp
 *
 *  Created on: 08.06.2016
 *      Author: Adrian
 */

#include "CommandMessage.h"

CommandMessage::CommandMessage() {
	// TODO Auto-generated constructor stub

}

CommandMessage::~CommandMessage() {
	// TODO Auto-generated destructor stub
}

std::string CommandMessage::getCommandString(){
	return *command;
}

void CommandMessage::setCommandString(std::vector<uint8_t> commandString){
	this->command = new std::string(commandString.begin(),commandString.end());
}

uint8_t CommandMessage::getCommandHex(){
	return commandHex;
}

void CommandMessage::setCommandHex(uint8_t hexValue){
	this->commandHex = hexValue;
}

