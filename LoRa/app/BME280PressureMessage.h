/**
 * @file BME280PressureMessage.h
 *
 * @author Adrian
 * @date Jun 1, 2016
 */

#ifndef BME280PRESSUREMESSAGE_H_
#define BME280PRESSUREMESSAGE_H_

#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

/**
 * @class BME280PressureMessage
 * @brief A Container that can hold acquired humidity values. The container will be
 * transported via a MessageQueue between different Tasks.
 */
class BME280PressureMessage: public SensorMessage {
public:
	BME280PressureMessage();
	virtual ~BME280PressureMessage();

	/**
	 * Sets the pressure value of the BME280PressureMessage
	 * @param pressure
	 */
	void setPressure(float pressure);

	/**
	 * Gets the pressure value from the BME280PressureMessage
	 * @return
	 */
	float getPressure();

	/**
	 * Gets a small LoRaMessage Type Formated String from the BMEPressureMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float pressure;
};

#endif /* BME280PRESSUREMESSAGE_H_ */
