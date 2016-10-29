/**
 * @file SensorMessage.h
 *
 * @author Adrian
 * @date 01.06.2016
 *
 */

#ifndef SENSORMESSAGE_H_
#define SENSORMESSAGE_H_

#include <string>
#include <vector>
#include <stdint.h>

/**
 * @class SensorMessage
 * @brief The Base Class of a Container that can hold acquired values from a Sensor. The container will be
 * transported via a MessageQueue between different Tasks.
 */
class SensorMessage {
public:
	SensorMessage();
	virtual ~SensorMessage();

	/**
	 * Gets a small LoRaMessage Type Formated String from the SensorMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Gets a small LoRaMessage Type Formatted Binary version of the SensorMessage.
	 * This Binaries can later be used for transportation via LoRa
	 * @return
	 */
	virtual std::vector<uint8_t>* getLoRaMessageBinary();

protected:
	std::string loraMessage;
	std::vector<uint8_t> loraMessageBinary;
	std::vector<std::string> loraMessageId;
private:
//	virtual char* getLoRaMessageId();

};

#endif /* SENSORMESSAGE_H_ */
