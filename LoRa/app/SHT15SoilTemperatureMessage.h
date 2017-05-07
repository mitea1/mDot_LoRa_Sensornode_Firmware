/*
 * SHT15SoilMeasurmentMessage.h
 *
 *  Created on: 09.01.2017
 *      Author: Adrian
 */

#ifndef APP_SHT15SOILTEMPERATUREMESSAGE_H_
#define APP_SHT15SOILTEMPERATUREMESSAGE_H_

#include "SensorMessage.h"

class SHT15SoilTemperatureMessage: public SensorMessage {
public:
	SHT15SoilTemperatureMessage();
	virtual ~SHT15SoilTemperatureMessage();

	/**
	 * Gets a small LoRaMessage Type Formated String from the  SHT15SoilTemperatureMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Sets the soil temperature value of the SHT15SoilTemperatureMessage
	 * @param soilTemperature
	 */
	void setSoilTemperature(float soilTemperature);


	/**
	 * Gets the soil temperature value from the SHT15SoilTemperatureMessage
	 * @return
	 */
	float getSoilTemperature();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the SHT15SoilTemperatureMessage.
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
	}soilTemperature;
};

#endif /* APP_SHT15SOILTEMPERATUREMESSAGE_H_ */
