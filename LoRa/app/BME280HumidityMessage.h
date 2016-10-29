/**
 * @file BME280HumidityMessage.h
 *
 * @author Adrian
 * @date Jun 1, 2016
 */

#ifndef BME280HUMIDITYMESSAGE_H_
#define BME280HUMIDITYMESSAGE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

/**
 * @class BME280HumidityMessage
 * @brief A Container that can hold acquired humidity values from the BME280. The container will be
 * transported via a MessageQueue between different Tasks.
 */
class BME280HumidityMessage: public SensorMessage {
public:
	BME280HumidityMessage();
	virtual ~BME280HumidityMessage();

	/**
	 * Sets the humidity value of the BME280HumidityMessage
	 * @param humidity to be stored
	 */
	void setHumidity(float humidity);

	/**
	 * Gets the humidity value from the BME280HumidityMessage
	 * @return
	 */
	float getHumidity();

	/**
	 * Gets a small LoRaMessage Type Formated String from the BMEHumidityMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the BMEHumidityMessage.
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
	}humidity;

};

#endif /* BME280HUMIDITYMESSAGE_H_ */
