/**
 * @file UBloxGPSMessage.h
 *
 * @author Adrian
 * @date 01.06.2016
 *
 */

#ifndef UBLOXGPSMESSAGE_H_
#define UBLOXGPSMESSAGE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

/**
 * @class UBloxGPSMessage
 * @brief A Container that can hold acquired gps values from the uBLOX. The container will be
 * transported via a MessageQueue between different Tasks.
 */

class UBloxGPSMessage: public SensorMessage {
public:
	UBloxGPSMessage();
	virtual ~UBloxGPSMessage();


	/**
	 * @brief Sets the longitude value of the uBloxGPSMessage
	 * @param longitude longitude value to be stored
	 */
	void setLongitude(float longitude);

	/**
	 * @brief Sets the latitude value of the uBloxGPSMessage
	 * @param latitude latitude value to be stored
	 */
	void setLatitude(float latitude);


	/**
	 * @brief Gets the longitude value of the uBloxGPSMessage
	 * @return
	 */
	float getLongitude();

	/**
	 * @brief Gets the latitude value of the uBloxGPSMessage
	 * @return
	 */
	float getLatitude();

	/**
	 * Gets a small LoRaMessage Type Formated String from the uBloxGPSMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the uBloxGPSMessage.
	 * This binary representation can later be used for transportation via LoRa
	 * @return
	 */
	virtual std::vector<uint8_t>* getLoRaMessageBinary();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	union{
		float floatValue;
		uint8_t uintValue[sizeof(float)];
	}longitude,latitude;

};


#endif /* UBLOXGPSMESSAGE_H_ */
