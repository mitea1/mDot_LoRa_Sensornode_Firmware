/*
 * CommandMessage.h
 *
 *  Created on: 08.06.2016
 *      Author: Adrian
 */
#include <string>
#ifndef APP_COMMANDMESSAGE_H_
#define APP_COMMANDMESSAGE_H_

class CommandMessage {
public:
	CommandMessage();
	virtual ~CommandMessage();

	std::string getCommandString();
private:
	std::string command;

	void setCommandString(std::string);
};

#endif /* APP_COMMANDMESSAGE_H_ */
