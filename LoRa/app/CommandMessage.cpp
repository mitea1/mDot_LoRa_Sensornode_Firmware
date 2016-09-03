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
	return command;
}

void CommandMessage::setCommandString(std::string commandString){
	this->command = commandString;
}

