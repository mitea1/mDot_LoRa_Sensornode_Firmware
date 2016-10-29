/**
 * @file MPU9250GyroscopeMessage.h
 *
 * @author Adrian
 * @date 01.06.2016
 *
 */

#ifndef MPU9250GYROSCOPEMESSAGE_H_
#define MPU9250GYROSCOPEMESSAGE_H_
#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

class MPU9250GyroscopeMessage: public SensorMessage {
public:
	MPU9250GyroscopeMessage();
	virtual ~MPU9250GyroscopeMessage();

	/**
	 * Sets the x-axis gyroscope value of the MPU9250GyroscopeMessage
	 * @param xGyro x-axis Gyroscope value to be stored
	 */
	void setXGyro(float xGyro);

	/**
	 * Sets the y-axis gyroscope value of the MPU9250GyroscopeMessage
	 * @param yGyro y-axis Gyroscope value to be stored
	 */
	void setYGyro(float yGyro);

	/**
	 * Sets the z-axis gyroscope value of the MPU9250GyroscopeMessage
	 * @param zGyro z-axis Gyroscope value to be stored
	 */
	void setZGyro(float zGyro);


	/**
	 * Gets the x-axis gyroscope value from the MPU9250GyroscopeMessage
	 * @return
	 */
	float getXGyro();

	/**
	 * Gets the y-axis gyroscope value from the MPU9250GyroscopeMessage
	 * @return
	 */
	float getYGyro();

	/**
	 * Gets the z-axis gyroscope value from the MPU9250GyroscopeMessage
	 * @return
	 */
	float getZGyro();

	/**
	 * Gets a small LoRaMessage Type Formated String from the  MPU9250GyroscopeMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the MPU9250GyroscopeMessage.
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
	}xGyro,yGyro,zGyro;

};


#endif /* MPU9250GYROSCOPEMESSAGE_H_ */
