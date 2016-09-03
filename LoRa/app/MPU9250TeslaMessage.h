/**
 * @file MPU9250TeslaMessage.h
 *
 * @author Adrian
 * @date 01.06.2016
 *
 */
#include <stdio.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

#ifndef MPU9250TESLAMESSAGE_H_
#define MPU9250TESLAMESSAGE_H_

#define MPU9250_X_TESLA_MESSAGE_ID		"M7"
#define MPU9250_Y_TESLA_MESSAGE_ID		"M8"
#define MPU9250_Z_TESLA_MESSAGE_ID		"M9"

/**
 * @class MPU9250TeslaMessage
 * @brief A Container that can hold acquired tesla values from the MPU9250. The container will be
 * transported via a MessageQueue between different Tasks.
 */
class MPU9250TeslaMessage: public SensorMessage {
public:
	MPU9250TeslaMessage();
	virtual ~MPU9250TeslaMessage();

	/**
	 * Sets the x-axis tesla value of the MPU9250TeslaMessage
	 * @param xTesla x-axis tesla value to be stored
	 */
	void setXTesla(float xTesla);

	/**
	 * Sets the y-axis tesla value of the MPU9250TeslaMessage
	 * @param yTesla y-axis tesla value to be stored
	 */
	void setYTesla(float yTesla);

	/**
	 * Sets the z-axis tesla value of the MPU9250TeslaMessage
	 * @param zTesla z-axis tesla value to be stored
	 */
	void setZTesla(float zTesla);


	/**
	 * Gets the x-axis tesla value from the MPU9250TeslaMessage
	 * @return
	 */
	float getXTesla();

	/**
	 * Gets the x-axis tesla value from the MPU9250TeslaMessage
	 * @return
	 */
	float getYTesla();

	/**
	 * Gets the x-axis tesla value from the MPU9250TeslaMessage
	 * @return
	 */
	float getZTesla();

	/**
	 * Gets a small LoRaMessage Type Formated String from the  MPU9250TeslaMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	float xTesla;
	float yTesla;
	float zTesla;

};


#endif /* MPU9250TESLAMESSAGE_H_ */
