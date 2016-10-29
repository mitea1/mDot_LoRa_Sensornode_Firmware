/**
 * @file LoRaMeasuermentMessage.h
 *
 * @author Adrian
 * @date 13.06.2016
 */

#ifndef APP_LORAMEASUERMENTMESSAGE_H_
#define APP_LORAMEASUERMENTMESSAGE_H_

#include <stdio.h>
#include <stdint.h>
#include <string>
#include <vector>
#include "SensorMessage.h"

/**
 * @class LoRaMeasurementMessage
 * @brief A Container that can hold acquired measurement values such as Rssi, Snr and some other config values from the LoRa Module.
 * The container will be transported via a MessageQueue between different Tasks and its intended to stored measurement results.
 */
class LoRaMeasurementMessage: public SensorMessage {
public:
	LoRaMeasurementMessage();
	virtual ~LoRaMeasurementMessage();


	/**
	 * @brief Sets the rssi value of the LoRaMeasurementMessage
	 * @param rssi rssi value to be stored
	 */
	void setRssi(int16_t rssi);

	/**
	 * @brief Gets the stored rssi value of the LoRaMeasurmentMessage
	 * @return
	 */
	int16_t getRssi();

	/**
	 * @brief Sets the snr value of the LoRaMeasurementMessage
	 * @param snr snr value to be stored
	 */
	void setSnr(int16_t snr);

	/**
	 * @brief Gets the stored snr value of the LoRaMeasurementMessage
	 * @return
	 */
	int16_t getSnr();

	/**
	 * @brief Sets the spreadingFactor of the LoRaMeasurementMessage
	 * @param spreadingFactor spreading Factor to be stored
	 */
	void setSpreadingFactor(uint8_t spreadingFactor);

	/**
	 * @brief Gets the stored spreading Factor of the LoRaMeasurementMessage
	 * @return
	 */
	uint8_t getSpreadingFactor();

	/**
	 * @brief Sets the tx Power value in dBm of the LoRaMeasurementMessage
	 * @param txPowerdBm tx Power in dBm to be stored
	 */
	void setTxPowerdBm(uint8_t txPowerdBm);

	/**
	 * @breif Gets the stored tx Power in dBm of the LoRaMeasurementMessage
	 * @return
	 */
	uint8_t getTxPowerdBm();

	/**
	 * Gets a small LoRaMessage Type Formated String from the LoRaMeasurmentMessage.
	 * This String can later be used for transportation via LoRa
	 * @return
	 */
	virtual char* getLoRaMessageString();

	/**
	 * Gets a small LoRaMessage Type Formated Binary representation from the LoRaMeasurementMessage.
	 * This binary representation can later be used for transportation via LoRa
	 * @return
	 */
	virtual std::vector<uint8_t>* getLoRaMessageBinary();

private:
	std::string loraMessage;
	std::vector<std::string> loraMessageId;

	int16_t rssi;
	int16_t snr;
	uint8_t spreadingFactor;
	uint8_t txPowerdBm;


};

#endif /* APP_LORAMEASUERMENTMESSAGE_H_ */
