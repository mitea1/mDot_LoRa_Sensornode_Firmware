/*
 * SHT10.h
 *
 *  Created on: 08.12.2016
 *      Author: Adrian
 */

#ifndef APP_SHT10_H_
#define APP_SHT10_H_

#include <mbed.h>
#include "cmsis_os.h"
#include "wait_api.h"

#define SHT11_RESET                 0x1e
#define SHT11_TEMP                  0x03
#define SHT11_HUMIDITIY             0x05
#define SHT11_R_STATUS              0x07
#define SHT11_W_STATUS              0x06
#define SHT11_RESET_TIME_MS         11
#define SHT11_MAX_READOUT_TIME      320e-3
#define SHT11_TEMPERATURE_OFFSET    -3965
#define MCLK                        8000

#define setupDelay() 				wait_us(50);
#define clockDelay()                wait_us(100);

class SHT10 {
public:
    SHT10(PinName data,PinName clk);
    virtual ~SHT10();

    float getTemperature();
    float getHumidity();
    void setupInterface();
    void resetInterface();
    void start();
    bool sendByte(uint_fast8_t);
    uint_fast8_t readByte(bool);


protected:
    mbed::DigitalInOut* data;
    mbed::DigitalInOut* clk;

//    void setupInterface();
//    void resetInterface();
//    void start();
//    bool sendByte(uint_fast8_t);
//    uint_fast8_t readByte(bool);
};

#endif /* APP_SHT10_H_ */
