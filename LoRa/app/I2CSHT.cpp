/*
 * I2C_SHTSHT.cpp
 *
 *  Created on: 08.01.2017
 *      Author: Adrian
 */

#include "I2CSHT.h"

namespace SHTx {
I2C_SHT::I2C_SHT(PinName sda, PinName scl) :
    scl_pin(scl), sda_pin(sda), frequency(10) {
        this->sda_pin.output();
        this->scl_pin.output();
    }

    void
    I2C_SHT::setFrequency(uint32_t hz) {
        this->frequency = (1000000 / hz);
    }

    void
    I2C_SHT::start(void) {
        this->output();
        this->sda(1);
        this->scl(1);
        this->sda(0);
        this->scl(0);
        this->scl(1);
        this->sda(1);
        this->scl(0);
    }

    void
    I2C_SHT::stop(void) {
        this->output();
        this->sda(0);
        this->scl(1);
        this->sda(1);
    }

    bool
    I2C_SHT::wait(void) {
        bool ack = false;

        this->input();
        for (uint8_t i = 0; i < 500 && !ack; i++) {
            wait_ms(1);
            ack = !this->sda_pin;
        }

        return ack;
    }

    void
    I2C_SHT::reset(void) {
        this->output();
        for (uint8_t i = 9; i; i--) {
            this->shift_out(1);
        }
        this->start();
        this->scl(1);
    }

    bool
    I2C_SHT::write(uint8_t data) {
        bool ack;

        this->output();
        for (uint8_t i = 8; i; i--) {
            this->shift_out(data & 0x80);
            data <<= 1;
        }

        this->input();
        ack = !this->shift_in();

        return ack;
    }

    uint8_t
    I2C_SHT::read(bool ack) {
        uint8_t data = 0;

        this->input();
        for (uint8_t i = 8; i; i--) {
            data <<= 1;
            data  |= this->shift_in();
        }

        this->output();
        this->shift_out(!ack);

        return data;
    }

    void
    I2C_SHT::output(void) {
        this->sda_pin.output();
    }

    void
    I2C_SHT::input(void) {
        this->sda_pin.input();
    }

    void
    I2C_SHT::sda(bool value) {
        this->sda_pin = value;
        wait_us(this->frequency);
    }

    void
    I2C_SHT::scl(bool value) {
        this->scl_pin = value;
        wait_us(this->frequency);
    }

    void
    I2C_SHT::shift_out(bool bit) {
        this->sda(bit);
        this->scl(1);
        this->scl(0);
    }

    bool
    I2C_SHT::shift_in(void) {
        wait_us(this->frequency);
        this->scl(1);
        bool bit = this->sda_pin;
        this->scl(0);
        return bit;
    }
}

