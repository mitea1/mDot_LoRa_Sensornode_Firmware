/**
 * @file CommandMessage.h
 *
 * @author Adrian
 * @date 08.06.2016
 *
 */
#ifndef APP_COMMANDMESSAGE_H_
#define APP_COMMANDMESSAGE_H_

#include <string>
#include <vector>
#include <stdint.h>

class CommandMessage {
public:
	CommandMessage();
	virtual ~CommandMessage();

	std::string getCommandString();
	void setCommandString(std::vector<uint8_t> commandMessage);
	uint8_t getCommandHex();
	void setCommandHex(uint8_t hexValue);
private:
	std::string* command;
	uint8_t commandHex;

};

#endif /* APP_COMMANDMESSAGE_H_ */
