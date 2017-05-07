/*
 * LoRaMessageBuilder.h
 *
 *  Created on: 15.12.2016
 *      Author: Adrian
 */

#ifndef APP_LORAMESSAGEBUILDER_H_
#define APP_LORAMESSAGEBUILDER_H_
#include <string>
#include <vector>
#include <stdint.h>
#include "SensorMessage.h"
#include "RawSerial.h"

class LoRaMessageBuilder {
public:
	LoRaMessageBuilder();
	virtual ~LoRaMessageBuilder();

	void appendLoRaMessage(void* message);

	std::string* getMessageAscii();
	std::vector<uint8_t>* getMessageByte();
	std::vector<uint8_t>* getMessageReceive();
	SensorMessage* getSensorMessage();

private:
	std::string* messageAscii;
	std::vector<uint8_t>* messageByte;
	std::vector<uint8_t>* messageReceive;

	SensorMessage* sensorMessage;

};

#endif /* APP_LORAMESSAGEBUILDER_H_ */
