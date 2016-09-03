/**
 * @file Decoder.h
 *
 * @author Adrian
 * @date 16.05.2016
 */

#ifndef APP_DECODER_H_
#define APP_DECODER_H_

#include <RawSerial.h>

#define HEADER_LENGHT 2
#define ID_LENGHT 2
#define LENGHT_LENGHT 2
#define PAYLOAD_LENGHT 28
#define CRC_LENGHT 2
#define MESSAGE_LENGHT (HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+PAYLOAD_LENGHT+CRC_LENGHT)

/**
 * States in which the Decoder can be
 */
enum DecoderState{
	INIT = 0,//!< INIT
	RECEIVE, //!< RECEIVE
	DECODE,  //!< DECODE
};

/**
 * Container that can hold GPS Information
 */
typedef struct POSLHH{
	unsigned long iTOW;
	long lon;
	long lat;
	long height;
	long hMSL;
	unsigned long hAcc;
	unsigned long vAcc;
};

/**
 * @class Decoder
 * @brief This Class is used to decode the byte stream thats sent from the uBlox. At the moment
 * it only decodes the NAV-POLLSH byte stream. For correct usage all other messages of the uBlox
 * needs to be deactivated or at least the NAV-POLLSH needs to be activated
 */
class Decoder {
public:
	Decoder(mbed::RawSerial*);
	virtual ~Decoder();

	/**
	 * @brief Gets the actual State in which the decoder is
	 * @return
	 */
	DecoderState getActualState();

	/**
	 * @brief Gets the receive Buffer in which all received Bytes from the NAV-POLLSH are
	 * stored
	 * @return
	 */
	char* getReceiveBuffer();

	/**
	 * @brief Gets the last successfully decoded NAV-POLLSH Bytestream
	 * @return
	 */
	POSLHH getLastPoslhh();

private:
	DecoderState actualState;
	mbed::RawSerial* serial;
	char lastReceivedChar;
	POSLHH lastPoslhh;
	char receiveBuffer[MESSAGE_LENGHT];
	int bufferPosition;

	/**
	 * @brief Sets the actual State of the Decoder
	 * @param actualState
	 */
	void setActualState(DecoderState actualState);

	/**
	 * @brief Gets the latest character from the serial internal buffer
	 */
	void getCharacterFromSerial();

	/**
	 * @brief Checks if the specific Char was the last received Char
	 * @param specificChar
	 * @return
	 */
	bool hasReceived(char specificChar);

	/**
	 * @brief Buffers the last received Char at the beginning of the buffer
	 */
	void bufferReceivedCharacterAtBegin();

	/**
	 * @brief Buffers the last received char at the actual position of the buffer
	 */
	void bufferReceivedCharacter();

	/**
	 * @brief Checks if the whole buffer is filled up
	 * @return
	 */
	bool isBufferFilled();

	/**
	 * @brief The Decoding routing thats called when some Data is recieved via the serial
	 */
	void rxInterrupt();

	/**
	 * @brief Sets the position where the next Byte should be stored inside the buffer
	 * @param desiredPosition
	 */
	void setBufferPosition(uint8_t desiredPosition);

	/**
	 * @brief Increments the position where the next Byte should be stored by 1
	 */
	void incrementBufferPosition();

	/**
	 * @brief Clears the whole buffer
	 */
	void clearReceiveBuffer();

	/**
	 * @brief Decodes the whole buffer
	 */
	void decodeReceiveBuffer();
};

#endif /* APP_DECODER_H_ */
