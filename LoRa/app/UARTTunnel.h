/**
 * @file UARTTUNNEL.h
 *
 * @author Adrian
 * @date 10.06.2016
 *
 */
#include "RawSerial.h"

#ifndef APP_UARTTUNNEL_H_
#define APP_UARTTUNNEL_H_

/**
 * @class UART_Tunnel
 * @brief Makes it possible to use the mDotDKs USB Connection as a COM-Port
 * to communicate directly with a device thats connected to the
 * STM32 Uart. Its main purpose is to control the uBlox via uCenter.
 */
class UART_Tunnel {
public:
	UART_Tunnel();
	UART_Tunnel(mbed::RawSerial*,mbed::RawSerial*);
	virtual ~UART_Tunnel();

private:
	mbed::RawSerial* uartSerial;
	mbed::RawSerial* usbSerial;

	/**
	 * @brief forwards every received byte from the uart to the usb serial
	 */
	void onUartRx();

	/**
	 * @brief forwards every received byte from the usb serial to uart
	 */
	void onUsbRx();
};

#endif /* APP_UARTTUNNEL_H_ */
