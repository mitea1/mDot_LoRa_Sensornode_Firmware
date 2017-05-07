/*
 * SHT15SoilMoistureMessage.h
 *
 *  Created on: 09.01.2017
 *      Author: Adrian
 */

#ifndef APP_SHT15SOILMOISTUREMESSAGE_H_
#define APP_SHT15SOILMOISTUREMESSAGE_H_

#include "SensorMessage.h"

class SHT15SoilMoistureMessage: public SensorMessage {
public:
	SHT15SoilMoistureMessage();
	virtual ~SHT15SoilMoistureMessage();
	/**
	 * Gets a small LoRaMessage Type Formated String from the  SHT15SoilMoistureMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Sets the soil temperature value of the SHT15SoilMoistureMessage
	 * @param soilTemperature
	 */
	void setSoilMoisture(float soilMoisture);


	/**
	 * Gets the soil moisture value from the SHT15SoilMoistureMessage
	 * @return
	 */
	float getSoilMoisture();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the SHT15SoilMoistureMessage.
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
	}soilMoisture;
};

#endif /* APP_SHT15SOILMOISTUREMESSAGE_H_ */
