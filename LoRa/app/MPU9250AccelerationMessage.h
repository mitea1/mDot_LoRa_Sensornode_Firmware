/**
 * @file MPU9250AccelerationMessage.h
 *
 * @author Adrian
 * @date 01.06.2016
 *
 */

#ifndef MPU9250ACCELERATIONMESSAGE_H_
#define MPU9250ACCELERATIONMESSAGE_H_
#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

/**
 * @class MPU9250AccelerationMessage
 * @brief A Container that can hold acquired acceleration values from the MPU9250. The container will be
 * transported via a MessageQueue between different Tasks.
 */
class MPU9250AccelerationMessage: public SensorMessage {
public:
	MPU9250AccelerationMessage();
	virtual ~MPU9250AccelerationMessage();

	/**
	 * Sets the x-axis acceleration value of the MPU9250AccelerationMessage
	 * @param xAcceleration x-axis acceleration to be stored
	 */
	void setXAcceleration(float xAcceleration);

	/**
	 * Sets the y-axis acceleration value of the MPU9250AccelerationMessage
	 * @param yAcceleration y-axis acceleration to be stored
	 */
	void setYAcceleration(float yAcceleration);

	/**
	 * Sets the z-axis acceleration value of the MPU9250AccelerationMessage
	 * @param zAcceleration
	 */
	void setZAcceleration(float zAcceleration);


	/**
	 * Gets the x-axis acceleration value from the MPU9250AccelerationMessage
	 * @return
	 */
	float getXAcceleration();

	/**
	 * Gets the y-axis acceleration value from the MPU9250AccelerationMessage
	 * @return
	 */
	float getYAcceleration();

	/**
	 * Gets the z-axis acceleration value from the MPU9250AccelerationMessage
	 * @return
	 */
	float getZAcceleration();

	/**
	 * Gets a small LoRaMessage Type Formated String from the  MPU9250AccelerationMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

private:

	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float xAcceleration;
	float yAcceleration;
	float zAcceleration;

};

#endif /* MPU9250ACCELERATIONMESSAGE_H_ */
