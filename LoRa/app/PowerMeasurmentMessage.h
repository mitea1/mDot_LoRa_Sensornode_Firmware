/*
 * PowerMeasurmentMessage.h
 *
 *  Created on: Oct 31, 2016
 *      Author: Adrian
 */

#ifndef POWERMEASURMENTMESSAGE_H_
#define POWERMEASURMENTMESSAGE_H_

#include "SensorMessage.h"

class PowerMeasurementMessage: public SensorMessage {
public:
	PowerMeasurementMessage();
	virtual ~PowerMeasurementMessage();

	void setShuntVoltage(float shuntVoltage);

	void setBusVoltage(float busVoltage);

	void setCurrent(float current);

	void setPower(float power);

	float getShuntVoltage(void);

	float getBusVoltage(void);

	float getCurrent(void);

	float getPower(void);

	virtual char* getLoRaMessageString();

	virtual std::vector<uint8_t>* getLoRaMessageBinary();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	union{
		float floatValue;
		uint8_t uintValue[sizeof(float)];
	}shuntVoltage,busVoltage,current,power;

};

#endif /* POWERMEASURMENTMESSAGE_H_ */
