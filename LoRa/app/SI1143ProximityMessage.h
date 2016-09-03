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

#ifndef APP_SI1143MESSAGE_H_
#define APP_SI1143MESSAGE_H_

#define SI1143_PROXIMITY_MESSAGE_ID		"P4"

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
	 * Gets a small LoRaMessage Type Formated String from the MAX44009Message.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	uint16_t proximity;
};

#endif /* APP_SI1143MESSAGE_H_ */
