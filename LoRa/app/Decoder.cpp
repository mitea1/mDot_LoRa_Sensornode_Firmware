/*
 * Decoder.cpp
 *
 *  Created on: 16.05.2016
 *      Author: Adrian
 */

#include "Decoder.h"
#include <RawSerial.h>

Decoder::Decoder(mbed::RawSerial* serial) {
	this->serial = serial;
	this->serial->attach(this,&Decoder::rxInterrupt,this->serial->RxIrq);
	setActualState(INIT);
	setBufferPosition(0);
}

Decoder::~Decoder() {

}

void Decoder::setActualState(DecoderState newState){
	actualState = newState;

}
DecoderState Decoder::getActualState(){
	return actualState;
}

void Decoder::getCharacterFromSerial(){
	lastReceivedChar = serial->getc();
}

bool Decoder::hasReceived(char specificChar){
	bool received=false;

	if(lastReceivedChar == specificChar){
		received = true;
		setActualState(RECEIVE);
	}

	return received;
}

void Decoder::bufferReceivedCharacterAtBegin(){
	receiveBuffer[0]=lastReceivedChar;
}

void Decoder::bufferReceivedCharacter(){
	receiveBuffer[bufferPosition]=lastReceivedChar;
	incrementBufferPosition();
}

void Decoder::setBufferPosition(uint8_t newPosition){
	bufferPosition = 0;
}

void Decoder::incrementBufferPosition(){
	if(getActualState()!=INIT && bufferPosition < MESSAGE_LENGHT){
		bufferPosition++;
	}
}

bool Decoder::isBufferFilled(){
	bool isFilled=false;
	if(bufferPosition==MESSAGE_LENGHT){
		isFilled=true;
	}
	return isFilled;
}

void Decoder::clearReceiveBuffer(){
	int i;
	for(i=0;i<MESSAGE_LENGHT;i++){
		receiveBuffer[i]=0x20;
	}
}

void Decoder::rxInterrupt(){
	if(serial->readable()){
		getCharacterFromSerial();

		if(hasReceived(0xB5)){
			setBufferPosition(0);
		}

		bufferReceivedCharacter();

		if(isBufferFilled()){
			decodeReceiveBuffer();
		}
	}
}

char* Decoder::getReceiveBuffer(){
	return receiveBuffer;
}

void Decoder::decodeReceiveBuffer(){

	lastPoslhh.iTOW = receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+3]<<24|
			receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+2]<<16|
			receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+1]<<8|
			receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+0];

	lastPoslhh.lon = receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+7]<<24|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+6]<<16|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+5]<<8|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+4];

	lastPoslhh.lat = receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+11]<<24|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+10]<<16|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+9]<<8|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+8];

	lastPoslhh.height = receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+15]<<24|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+14]<<16|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+13]<<8|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+12];

	lastPoslhh.hMSL = receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+19]<<24|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+18]<<16|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+17]<<8|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+16];

	lastPoslhh.hAcc = receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+23]<<24|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+22]<<16|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+21]<<8|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+20];

	lastPoslhh.vAcc = receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+27]<<24|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+26]<<16|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+25]<<8|
				receiveBuffer[HEADER_LENGHT+ID_LENGHT+LENGHT_LENGHT+24];

}

POSLHH Decoder::getLastPoslhh(){
	return lastPoslhh;
}

