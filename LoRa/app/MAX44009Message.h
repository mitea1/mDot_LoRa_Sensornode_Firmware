/**
 * @file MAX44009Message.h
 *
 * @author Adrian
 * @date 01.06.2016
 *
 */

#ifndef MAX44009MESSAGE_H_
#define MAX44009MESSAGE_H_

#include <stdio.h>
#include <stdint.h>
#include "SensorMessage.h"

/**
 * @class MAX44009Message
 * @brief A Container that can hold acquired lux values from the MAX44009. The container will be
 * transported via a MessageQueue between different Tasks.
 */
class MAX44009Message:public SensorMessage {
public:
	MAX44009Message();
	virtual ~MAX44009Message();

	/**
	 * Sets the lux value of the MAX44009 Message
	 * @param lux lux value to be stored
	 */
	void setLux(float lux);

	/**
	 * Gets the lux value from the MAX44009 Message
	 * @return
	 */
	float getLux();


	/**
	 * Gets a small LoRaMessage Type Formated String from the MAX44009Message.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the MAX44009Message.
	 * This binary representation can later be used for transportation via LoRa
	 * @return
	 */
	virtual std::vector<uint8_t>* getLoRaMessageBinary();

private:

	union{
		float floatValue;
		uint8_t uintValue [sizeof(float)];
	}lux;

};

#endif /* MAX44009MESSAGE_H_ */
