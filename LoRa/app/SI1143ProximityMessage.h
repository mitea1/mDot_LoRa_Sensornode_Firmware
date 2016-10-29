/**
 * @file SI1143ProximityMessage.h
 *
 * @author Adrian
 * @date 02.06.2016
 *
 */
#include <stdio.h>
#include <string>
#include <vector>
#include <stdint.h>
#include "SensorMessage.h"
#include "main.h"

#ifndef APP_SI1143MESSAGE_H_
#define APP_SI1143MESSAGE_H_



/**
 * @class SI1143ProximityMessage
 * @brief A Container that can hold acquired proximity values from the SI1143. The container will be
 * transported via a MessageQueue between different Tasks.
 */
class SI1143ProximityMessage: public SensorMessage {
public:
	SI1143ProximityMessage();
	virtual ~SI1143ProximityMessage();

	/**
	 * Sets the proximity value of the SI1143ProximityMessage
	 * @param proximity proximity value to be stored
	 */
	void setProximity(uint16_t proximity);

	/**
	 * Gets the proximity value from the SI1143ProximityMessage
	 * @return
	 */
	uint16_t getProximity();


	/**
	 * Gets a small LoRaMessage Type Formated String from the SI1143ProximityMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the SI1143ProximityMessage.
	 * This binary representation can later be used for transportation via LoRa
	 * @return
	 */
	virtual std::vector<uint8_t>* getLoRaMessageBinary();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	union{
		uint16_t uint16Value;
		uint8_t uint8Value[sizeof(uint16_t)];
	}proximity;

};

#endif /* APP_SI1143MESSAGE_H_ */
