/*
 * SHT10.cpp
 *
 *  Created on: 08.12.2016
 *      Author: Adrian
 */

#include "SHT10.h"

SHT10::SHT10(PinName data,PinName clk) {
    this->data = new mbed::DigitalInOut(data);
    this->clk = new mbed::DigitalInOut(clk);

    setupInterface();
    resetInterface();

}

SHT10::~SHT10() {
    // TODO Auto-generated destructor stub
    delete this->data;
    delete this->clk;
}

float SHT10::getTemperature(){
    uint16_t result = 0;
    start();
    sendByte(SHT11_TEMP);

    //Wait for data to be ready
    for(uint32_t i=0; i<(uint32_t)(MCLK*SHT11_MAX_READOUT_TIME);i++){
        if(data->read() == 0){
            break;
        }
    }

    result = readByte(true) << 8;
    result |= readByte(false);
    result += SHT11_TEMPERATURE_OFFSET;

    return result;

}

float SHT10::getHumidity(){

    uint16_t rawHumidity = 0;                    // Raw humidity value returned from sensor
    float linearHumidity = 0.0;       // Humidity with linear correction applied
    float correctedHumidity = 0.0;    // Temperature-corrected humidity
    float temperature = 0.0;          // Raw temperature value

    // Conversion coefficients from SHT15 datasheet
    const float C1 = -4.0;       // for 12 Bit
    const float C2 =  0.0405;    // for 12 Bit
    const float C3 = -0.0000028; // for 12 Bit
    const float T1 =  0.01;      // for 14 Bit @ 5V
    const float T2 =  0.00008;   // for 14 Bit @ 5V

    uint16_t result;
    start();
    sendByte(SHT11_HUMIDITIY);

    //Wait for data to be ready
    for(uint32_t i=0; i<(uint32_t)(MCLK*SHT11_MAX_READOUT_TIME);i++){
        if(data->read() == 0){
            break;
        }
    }

    rawHumidity = readByte(true) << 8;
    rawHumidity |= readByte(false);

    linearHumidity = C1 + C2 * rawHumidity + C3 * rawHumidity * rawHumidity;
    temperature = getTemperature();

    correctedHumidity = (temperature - 25.0) * (T1 + T2 * rawHumidity);

    return correctedHumidity;

}

void SHT10::setupInterface(){
    this->data->mode(OpenDrain);

    this->data->output();
    this->clk->output();

    this->data->write(1);
    this->clk->write(0);

    setupDelay();
}

void SHT10::resetInterface(){
    //Interface Reset
    for(int i = 0 ;i < 9 ;i++){
        this->clk->write(1);
        clockDelay();
        this->clk->write(0);
        clockDelay();
    }

    start();
    sendByte(SHT11_RESET);
    wait_ms(SHT11_RESET_TIME_MS);
}

void SHT10::start(){

	data->output();
	clk->output();

//	removed to prevent clock delay at the end of reset
//    setupDelay();
    clk->write(1);
    setupDelay();
    data->write(0);
    setupDelay();
    clk->write(0);
    clockDelay();
    clk->write(1);
    setupDelay();
    data->write(1);
    setupDelay();
    clk->write(0);
    setupDelay();
    wait_ms(10);

	data->input();
	clk->input();
}

bool SHT10::sendByte(uint_fast8_t byte){
	data->output();
	clk->output();

    for (int i=0; i<8; i++){
        uint8_t tmp = byte & 0x80;
        data->write(tmp);
        setupDelay();
        clk->write(1);
        clockDelay();
        clk->write(0);
        setupDelay();
        byte <<= 1;
    }

    data->write(1);
    setupDelay();
    clk->write(1);
    setupDelay();

    data->input();
    uint8_t error = data->read();
    //dbg_write_u8(&error, 1);
    clk->write(0);
    setupDelay();
    wait_ms(10);
    clk->input();
}

uint_fast8_t SHT10::readByte(bool acknowledge){
    uint_fast8_t result = 0;

    data->output();
    clk->output();

    data->write(1);

    data->input();
    for(int i = 0; i < 8; i++){

    	clk->write(1);
        result <<= 1;
        if(data->read() == 1){
            result |=1;
        }
        setupDelay();
        clk->write(0);
        setupDelay();
    }

    data->output();
    data->write(acknowledge ? 0 : 1);
    setupDelay();
    clk->write(1);
    clockDelay();
    clk->write(0);
    setupDelay();
    data->write(1);
    setupDelay();

    data->input();
    clk->input();

    return result;
}



