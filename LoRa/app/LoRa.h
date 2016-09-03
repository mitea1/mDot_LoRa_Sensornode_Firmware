/**
 * @file LoRa.h
 *
 * @author Adrian
 * @date May 31, 2016
 *
 */
#include "mDot.h"
#include "MTSLog.h"
#include "LoRaConfig.h"

#ifndef LORA_H_
#define LORA_H_

/**
 * @class LoRa
 * @brief Represents the LoRa Module with all its functionality. It wraps Multitech owns mDot Library functions.
 * It's possible to wrap other functionality from other LoRa Module Manufactures for future use cases
 */
class LoRa {
public:
	LoRa(mDot*,RawSerial*);
	virtual ~LoRa();

	/**
	 * @brief Initializes and start the LoRa Module depending on the desireMode
	 * @param desiredMode
	 */
	void init(LORA_MODE desiredMode);

	/**
	 * @brief Sends data stored inside a vector via LoRa
	 * @param dataToSend the vector that contains the Data that needs to be sent
	 * @return
	 */
	int32_t send(std::vector<uint8_t>& dataToSend);

	/**
	 * @brief Receives data via LoRa and stores it inside a vector
	 * @param receivedData the vector where the received data needs to be stored
	 * @return
	 */
	int32_t recv(std::vector<uint8_t>& receivedData);

	/**
	 * @brief Gets the Rssi of the last sent Message. It's important that at least 1
	 * Acknowledgment Retries is set by setAckRetries()
	 * @return
	 */
	int16_t getLastRssi();

	/**
	 * @brief DON'T USE IT RESULTS IN HARDFAULT!
	 * Gets the SNR of the last sent Message.
	 * @return
	 */
	int16_t getLastSnr();

	/**
	 * @brief Gets the actual spreading Factor from 7 to 12 from the LoRa Module
	 * @return
	 */
	uint8_t getSpreadingFactor();

	/**
	 * @brief Gets the actual transmit Power in dBm from the LoRa Module
	 * @return
	 */
	uint8_t getTxPowerdBm();

	/**
	 * @brief Sends a 0 Byte long ping message to the gateway
	 */
	void ping();


	/**
	 * @brief  Get ms until next free channel
     * only applicable for European models, US models return 0
	 */
	uint32_t getNextTxMs();



private:
	mDot* dot;
	RawSerial* debugSerial;

	LoRaConfig* config;

	int16_t rssi;
	int16_t snr;
	uint8_t spreadingFactor;
	uint8_t txPowerdBm;

	/**
	 * @brief Depending on the LoRaConfig it defines wheter the LoRa Module connects to a
	 * public network or not
	 * @return
	 */
	int32_t setPublicNetwork();

	/**
	 * @brief Depending on the LoRaConfig it defines the frequency SubBand that is used for
	 * transmission of Message to the Gateway
	 * @return
	 */
	int32_t setFrequencySubBand();

	/**
	 * @brief Depending on the LoRaConfig it defines the name of the Network the
	 * LoRa Module signs up
	 * @return
	 */
	int32_t setNetworkName();

	/**
	 * @brief Depending on the LoRaConfig it defines the Passphrase thats used to
	 * use the Network
	 * @return
	 */
	int32_t setNetworkPassphrase();

	/**
	 * @brief Depending on the LoRaConfig it defines that AppEUI thats used for OTAA
	 * @return
	 */
	int32_t setAppEUI();

	/**
	 * @brief Depending on the LoRaConfig it defines that AppKey thats used for OTAA
	 * @return
	 */
	int32_t setAppKey();

	/**
	 * @brief Depending on the LoRaConfig it defines that DeviceEUI thats used for OTAA
	 * @return
	 */
	int32_t setDeviceEUI();


	/**
	 * @brief Depending on the LoRaConfig it sets the join mode of the Node.
	 * Either OTTA (Over the Air Activation or ABP (Activation by Personalization)
	 * @param
	 * @return
	 */
	int32_t setJoinMode();

	/**
	 * @brief Depending on the LoRaConfig it defines the spreading Factor
	 * for transmissions via LoRa
	 * @return
	 */
	int32_t setSpreadingFactor();

	/**
	 * @brief Depending on the LoRaConfig it defines the number of Acknowledgment Retries
	 * that are made
	 * @return
	 */
	int32_t setAckRetries();

	/**
	 * @brief Depending on the LoRaConfig it defines the power of LoRa data Transmission
	 * @return
	 */
	int32_t setTxPower();

	/**
	 * @brief Saves parameters of the LoRa Module
	 */
	void saveConfig();

	/**
	 * @brief Resets Configuration of the LoRa Module
	 */
	void resetConfig();

	/**
	 * @brief Tries to join the Network defined by NetworkName and NetworkPassphrase
	 */
	void joinNetwork();



};

#endif /* LORA_H_ */
