/*
 * SHT15.cpp

 *
 *  Created on: 08.01.2017
 *      Author: Adrian
 */
#include "SHT15.h"

namespace SHTx {
    SHT15::SHT15(PinName sda, PinName scl): i2c(sda, scl) {
        this->ready = true;
        wait_ms(11);
    }

    float
    SHT15::getTemperature(void) {
        return this->convertTemperature(
            this->temperature,
            this->getFlag(flag_resolution),
            this->scale
        );
    }

    float
    SHT15::getHumidity(void) {
        return this->convertHumidity(
            this->humidity,
            this->temperature,
            this->getFlag(flag_resolution)
        );
    }

    bool
    SHT15::checkBattery(void) {
        this->readRegister(SHT10_READ_REGISTER);
        return this->getFlag(flag_battery);
    }

    bool
    SHT15::setHeater(bool value) {
        this->setFlag(flag_heater, value);
        return this->writeRegister();
    }

    bool
    SHT15::setResolution(bool value) {
        this->setFlag(flag_resolution, value);
        return this->writeRegister();
    }

    bool
    SHT15::setOTPReload(bool value) {
        this->setFlag(flag_otp_reload, !value);
        return this->writeRegister();
    }

    void
    SHT15::setScale(bool value) {
        this->scale = value;
    }

    bool
    SHT15::update(void) {
        if ((this->ready == false) ||
            !this->readRegister(SHT10_READ_TEMPERATURE) ||
            !this->readRegister(SHT10_READ_HUMIDITY)) {
            return false;
        }

        return true;
    }

    bool
    SHT15::reset(void) {
        while (this->ready == false) {
            continue;
        }

        this->ready = false;
        this->i2c.start();
        bool ack = this->i2c.write(SHT10_RESET_DEVICE);
        this->i2c.stop();
        this->ready = true;

        if (ack) {
            this->status_register = 0;
            this->humidity = 0;
            this->temperature = 0;
            wait_ms(11);
            return true;
        }

        return false;
    }

    void
    SHT15::connectionReset(void) {
        this->i2c.reset();
    }

    float
    SHT15::convertTemperature(uint16_t sot, bool res, bool scale) {
        // Temperature conversion coefficients
        float d1 = this->coefficient.dv[scale];
        float d2 = ((scale) ? this->coefficient.df[res]
                            : this->coefficient.dc[res]);

        // Temperature data conversion
        return d1 + (d2 * (float)(sot));
    }

    float
    SHT15::convertHumidity(uint16_t sohr, uint16_t sot, bool res) {
        // Humidity conversion coefficients
        float c1 = this->coefficient.c1[res];
        float c2 = this->coefficient.c2[res];
        float c3 = this->coefficient.c3[res];

        // Temperature compensation coefficients
        float t1 = this->coefficient.t1[res];
        float t2 = this->coefficient.t2[res];

        // Temperature data conversion to celcius
        float temp = this->convertTemperature(sot, res, false);

        // Humidity data conversion to relative humidity
        float humid = c1 + (c2 * (float)(sohr)) + (c3 * (float)(sohr * sohr));

        // Calculate temperature compensation
        return (temp - 25) + (t1 + (t2 * (float)(sohr)) + humid);
    }

    bool
    SHT15::writeRegister(void) {
        while (this->ready == false) {
            continue;
        }

        this->ready = false;
        this->i2c.start();

        if (this->i2c.write(SHT10_WRITE_REGISTER)) {
            this->i2c.write(this->status_register);
        }

        this->i2c.stop();
        this->ready = true;

        return true;
    }

    bool
    SHT15::readRegister(cmd_list command) {
        while (this->ready == false) {
            continue;
        }

        this->ready = false;
        this->i2c.start();

        if (!this->i2c.write(command)) {
            this->i2c.stop();
            return false;
        }

        switch (command) {
            case SHT10_READ_TEMPERATURE: {
                if (!this->i2c.wait()) {
                    this->i2c.stop();
                    return false;
                }

                this->temperature  = this->i2c.read(1) << 8;
                this->temperature |= this->i2c.read(0);
            } break;

            case SHT10_READ_HUMIDITY: {
                if (!this->i2c.wait()) {
                     this->i2c.stop();
                    return false;
                }

                this->humidity  = this->i2c.read(1) << 8;
                this->humidity |= this->i2c.read(0);
            } break;

            case SHT10_READ_REGISTER: {
                this->status_register = this->i2c.read(0);
            } break;
        }

        this->i2c.stop();
        this->ready = true;

        return true;
    }

    bool
    SHT15::getFlag(SHT15::flag_list flag) {
        return (this->status_register & flag) ? true : false;
    }

    void
    SHT15::setFlag(SHT15::flag_list flag, bool value) {
        if (value) {
            this->status_register |= flag;
        } else {
            this->status_register &= ~flag;
        }
    }
}
