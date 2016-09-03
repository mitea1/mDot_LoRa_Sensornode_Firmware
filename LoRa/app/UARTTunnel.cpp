/*
 * UARTTunnel.cpp
 *
 *  Created on: 10.06.2016
 *      Author: Adrian
 */

#include "UARTTunnel.h"

UART_Tunnel::UART_Tunnel() {
	this->uartSerial = new mbed::RawSerial(XBEE_DOUT,XBEE_DIN);
	this->usbSerial = new mbed::RawSerial(USBTX,USBRX);

	uartSerial->baud(9600);
	usbSerial->baud(9600);
	uartSerial->attach(this,&UART_Tunnel::onUartRx,this->uartSerial->RxIrq);
	usbSerial->attach(this,&UART_Tunnel::onUsbRx,this->usbSerial->RxIrq);

}
UART_Tunnel::UART_Tunnel(mbed::RawSerial* uartSerial,mbed::RawSerial* usbSerial){
	this->uartSerial =  uartSerial;
	this->usbSerial = usbSerial;

	uartSerial->attach(this,&UART_Tunnel::onUartRx,this->uartSerial->RxIrq);
	usbSerial->attach(this,&UART_Tunnel::onUsbRx,this->usbSerial->RxIrq);
}

UART_Tunnel::~UART_Tunnel() {
	// TODO Auto-generated destructor stub
}

void UART_Tunnel::onUartRx(){
	if(uartSerial->readable()){
		usbSerial->putc(uartSerial->getc());
	}
}

void UART_Tunnel::onUsbRx(){
	if(usbSerial->readable()){
		uartSerial->putc(usbSerial->getc());
	}

}

