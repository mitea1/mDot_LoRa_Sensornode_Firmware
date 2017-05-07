/*
 * I2CSHT.h
 *
 *  Created on: 08.01.2017
 *      Author: Adrian
 */

#ifndef APP_I2CSHT_H_
#define APP_I2CSHT_H_

#include "mbed.h"

namespace SHTx {
    /**
     * Class: I2C
     *  Humidity and Temperature Sensor - SHT15
     *  I2C Bit-bang master driver.
     */
    class I2C_SHT {
    private:
        DigitalInOut scl_pin;
        DigitalInOut sda_pin;

        uint32_t frequency;

    public:
        /**
         * Constructor: SHTx::I2C
           *  Create an I2C Master interface, connected to the specified pins.
         *  Bit-bang I2C driver to get around the lousy I2C implementation in the
         *  SHTx interface...
         *
         * Variables:
         *  sda - I2C data line pin
         *  scl - I2C clock line pin
         */
        I2C_SHT(PinName sda, PinName scl);

        /**
         * Function: setFrequency
         *  Set the frequency of the SHTx::I2C interface
         *
         * Variables:
         *  hz - The bus frequency in hertz
         */
        void setFrequency(uint32_t hz);

        /**
         * Function: start
         *  Issue start condition on the SHTx::I2C bus
         */
        void start(void);

        /**
         * Function: stop
         *  Issue stop condition on the SHTx::I2C bus
         */
        void stop(void);

        /**
         * Function: wait
         *  Wait for SHT15 to complete measurement.
         *  Max timeout 500ms.
         *
         * Variables:
         *  returns - true if an ACK was received, false otherwise
         */
        bool wait(void);

        /**
         * Function: reset
         *  If communication with the device is lost
         *  the command will reset the serial interface
         */
        void reset(void);

        /**
         * Function: write
         *  Write single byte out on the SHTx::I2C bus
         *
         * Variables:
         *  data     - data to write out on bus
         *  returns - true if an ACK was received, false otherwise
         */
        bool write(uint8_t data);

        /**
         * Function: write
         *  Read single byte form the I2C bus
         *
         * Variables:
         *  ack     - indicates if the byte is to be acknowledged
         *  returns - the read byte
         */
        uint8_t read(bool ack);

    private:
        /**
         * Function: output
         *  Configures sda pin as output
         */
        void output(void);

        /**
         * Function: input
         *  Configures sda pin as input
         */
        void input(void);

        /**
         * Function: sda
         *  Drive sda pin.
         *
         * Variables:
         *  value - drive pin high or low
         */
        void sda(bool value);

        /**
         * Function: scl
         *  Drive scl pin.
         *
         * Variables:
         *  value - drive pin high or low
         */
        void scl(bool value);

        /**
         * Function: shift_out
         *  Write single bit out on the SHTx::I2C bus
         *
         * Variables:
         *  bit - value of the bit to be written.
         */
        void shift_out(bool bit);

        /**
         * Function: shift_in
         *  Read single bit from the SHTx::I2C bus
         *
         * Variables:
         *  return - value of the bit read.
         */
        bool shift_in(void);
    };
}

#endif /* APP_I2CSHT_H_ */
