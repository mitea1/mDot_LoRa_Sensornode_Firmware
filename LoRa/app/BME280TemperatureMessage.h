/**
 * @file BME280TemperatureMessage.h
 *
 * @author Adrian
 * @date Jun 1, 2016
 */

#ifndef BME280TEMPERATUREMESSAGE_H_
#define BME280TEMPERATUREMESSAGE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

/**
 * @class BME280TemperatureMessage
 * @brief A Container that can hold acquired temperature values. The container will be
 * transported via a MessageQueue between different Tasks.
 */
class BME280TemperatureMessage: public SensorMessage {
public:
	BME280TemperatureMessage();
	virtual ~BME280TemperatureMessage();

	/**
	 * Set the temperature value of the BME280TemperatureMessage
	 * @param temperature
	 */
	void setTemperature(float temperature);

	/**
	 * Gets the temperature value from the BME280TemperatureMessage
	 * @return
	 */
	float getTemperature();


	/**
	 * Gets a small LoRaMessage Type Formated String from the BME280TemperatureMessage
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the BME280TemperatureMessage.
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
	}temperature;

};

#endif /* BME280TEMPERATUREMESSAGE_H_ */
