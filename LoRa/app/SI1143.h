/**
 * @file SI1143.h
 *
 * @author Adrian
 * @date 02.06.2016
 *
 */
#ifndef SI1143_H_
#define SI1143_H_

#include "mbed.h"
#include "I2C_RT.h"
#include "SI1143Config.h"


#define SI1143_IR_ADDRESS                  0x5A
#define SI1143_HW_KEY_VAL0                 0x17    //Value to write into the HW Key register

// Register Addresses

#define SI1143_PART_ID                     0x00
#define SI1143_REV_ID                      0x01
#define SI1143_SEQ_ID                      0x02    //Si114x-A11 (MAJOR_SEQ=1, MINOR_SEQ=1)
#define SI1143_INT_CFG                     0x03
#define SI1143_IRQ_ENABLE                  0x04
#define SI1143_IRQ_MODE1                   0x05
#define SI1143_IRQ_MODE2                   0x06
#define SI1143_HW_KEY                      0x07

#define SI1143_MEAS_RATE                   0x08
#define SI1143_ALS_RATE                    0x09
#define SI1143_PS_RATE                     0x0A

#define SI1143_ALS_LOW_TH0                 0x0B
#define SI1143_ALS_LOW_TH1                 0x0C
#define SI1143_ALS_HI_TH0                  0x0D
#define SI1143_ALS_HI_TH1                  0x0E

#define SI1143_PS_LED21                    0x0F
#define SI1143_PS_LED3                     0x10

#define SI1143_PS1_TH0                     0x11
#define SI1143_PS1_TH1                     0x12
#define SI1143_PS2_TH0                     0x13
#define SI1143_PS2_TH1                     0x14
#define SI1143_PS3_TH0                     0x15

#define SI1143_PS3_TH1                     0x16
#define SI1143_PARAM_WR                    0x17
#define SI1143_COMMAND                     0x18

#define SI1143_RESPONSE                    0x20
#define SI1143_IRQ_STATUS                  0x21

#define SI1143_ALS_VIS_DATA0               0x22
#define SI1143_ALS_VIS_DATA1               0x23
#define SI1143_ALS_IR_DATA0                0x24
#define SI1143_ALS_IR_DATA1                0x25

#define SI1143_PS1_DATA0                   0x26
#define SI1143_PS1_DATA1                   0x27
#define SI1143_PS2_DATA0                   0x28
#define SI1143_PS2_DATA1                   0x29
#define SI1143_PS3_DATA0                   0x2A
#define SI1143_PS3_DATA1                   0x2B


#define SI1143_AUX_DATA0                   0x2C
#define SI1143_AUX_DATA1                   0x2D

#define SI1143_PARAM_RD                    0x2E
#define SI1143_CHIP_STAT                   0x30
#define SI1143_ANA_IN_KEY                  0x3B

// Command Register Values

#define SI1143_PARAM_QUERY                 0x80    //Value is ORed with Parameter Offset
#define SI1143_PARAM_SET                   0xA0    //Value is ORed with Parameter Offset
#define SI1143_PARAM_AND                   0xC0    //Value is ORed with Parameter Offset
#define SI1143_PARAM_OR                    0xE0    //Value is ORed with Parameter Offset
#define SI1143_NOP                         0x00
#define SI1143_RESET                       0x01
#define SI1143_BUSADDR                     0x02
#define SI1143_PS_FORCE                    0x05
#define SI1143_ALS_FORCE                   0x06
#define SI1143_PSALS_FORCE                 0x07
#define SI1143_PS_PAUSE                    0x09
#define SI1143_ALS_PAUSE                   0x0A
#define SI1143_PSALS_PAUSE                 0x0B
#define SI1143_PS_AUTO                     0x0D
#define SI1143_ALS_AUTO                    0x0E
#define SI1143_PSALS_AUTO                  0x0F

// Ram Addresses

#define SI1143_I2C_ADDR                    0x00
#define SI1143_CHLIST                      0x01
#define SI1143_PSLED12_SELECT              0x02
#define SI1143_PSLED3_SELECT               0x03
#define SI1143_FILTER_EN                   0x04
#define SI1143_PS_ENCODING                 0x05
#define SI1143_ALS_ENCODING                0x06
#define SI1143_PS1_ADCMUX                  0x07
#define SI1143_PS2_ADCMUX                  0x08
#define SI1143_PS3_ADCMUX                  0x09
#define SI1143_PS_ADC_COUNTER              0x0A
#define SI1143_PS_ADC_GAIN                 0x0B
#define SI1143_PS_ADC_MISC                 0x0C
#define SI1143_ALS1_ADCMUX                 0x0D
#define SI1143_ALS2_ADCMUX                 0x0E
#define SI1143_ALS3_ADCMUX                 0x0F
#define SI1143_ALS_VIS_ADC_COUNTER         0x10
#define SI1143_ALS_VIS_ADC_GAIN            0x11
#define SI1143_ALS_VIS_ADC_MISC            0x12
#define SI1143_ALS_HYST                    0x16
#define SI1143_PS_HYST                     0x17
#define SI1143_PS_HISTORY                  0x18
#define SI1143_ALS_HISTORY                 0x19
#define SI1143_ADC_OFFSET                  0x1A
#define SI1143_SLEEP_CTRL                  0x1B
#define SI1143_LED_REC                     0x1C
#define SI1143_ALS_IR_ADC_COUNTER          0x1D
#define SI1143_ALS_IR_ADC_GAIN             0x1E
#define SI1143_ALS_IR_ADC_MISC             0x1F

// Measurement Channel List

#define SI1143_PS1_TASK                    0x01
#define SI1143_PS2_TASK                    0x02
#define SI1143_PS3_TASK                    0x04
#define SI1143_ALS_VIS_TASK                0x10
#define SI1143_ALS_IR_TASK                 0x20
#define SI1143_AUX_TASK                    0x40


/**
 * @class SI1143
 * @brief Provides Functionality to control  the SI1143 Sensor on the Sensbert
 */

class SI1143
{
    public:
        SI1143(I2C_RT*);


        /**
         * @brief Initializes the SI1143 according to the desired SI1143_MODE
         * @param desiredMode the desired Mode depending on which the SI1143 has
         * to be configured
         */
        void init(SI1143_MODE desiredMode);
        /**
         * @brief Restarts the Sensor and its functionality
         */
        void restart(void);


        /**
         * @brief Get the actual proximity that has been measured
         * @param repeat how many time the measurement has been taken to get an average
         * proximity value
         * @return
         */
        int getProximity(int repeat);

        /**
         * @brief Get the actual ambient light that has been measured
         * @param repeat how many time the measurement has been taken to get an average
         * ambient light value
         * @return
         */
        int getAmbientLight(int repeat);

        /**
		 * @brief Get the actual infrared light that has been measured
		 * @param repeat how many time the measurement has been taken to get an average
		 * infrared light value
		 * @return
		 */
        int getInfraRedLight(int repeat);


    private:

        I2C* i2c_;
        I2C_RT* i2c;
        int bias1,bias2,bias3;

        SI1143Config* config;

        /**
         * @brief Sends commands via i2c to the command register.
         * Is used to control the Sensor
         * @param cmd command to be sent to the command register
         */
        void command(uint8_t cmd);

        /**
         * @brief Configure SI1143 Interrupts internally
         * according to its SI1143Config
         */
        void configureInterrupts();

        /**
		 * @brief Sets the proximity sensing threshold of led 1
		 * according to its SI1143Config
		 */
		void setProximitySensing1Threshold();

};

#endif /* SI1143_H_ */
