/**
 * @file MAX44009.h
 *
 * @author Adrian
 * @date 16.05.2016
 */

#include <stdint-gcc.h>
#include <math.h>
#include "I2C_RT.h"
#include "MAX44009Config.h"

#ifndef APP_MAX44009_H_
#define APP_MAX44009_H_

#define MAX44009_ADRESS			0b10010100
#define MAX44009_CONFIG			0x02
#define MAX44009_LUX_H_BYTE		0x03
#define MAX44009_LUX_L_BYTE		0x04
#define MAX44009_LUX_H_L_BYTE	0x0304

#define MAX44009_INT_ENABLE		0x01
#define MAX44009_TH_UPPER		0x05
#define MAX44009_TH_LOWER		0x06

/**
 * @class MAX44009
 * @brief Provides Functionality to control  the MAX44009 Sensor on the Sensbert
 */
class MAX44009 {
public:
	MAX44009(I2C_RT*);
	virtual ~MAX44009();

	/**
	 * @brief Initializes the MAX44009 according to the desired MAX44009_MODE
	 * @param desiredMode the desired Mode depending on which the MAX44009 has to be
	 * configured
	 */
	void init(MAX44009_MODE desiredMode);

	/**
	 * @brief Returns the actual lux values that has been measured by the sensor
	 * @return
	 */
	float getLux();

private:
	I2C_RT* i2c;
	MAX44009Config* config;

	/**
	 * @brief Calculates the lux value according to the mantissa and exponent whose have been read
	 * from the sensor registers. Calculation is documented in the Datasheet of MAX44009
	 * @param mantissa 	read mantissa from Sensor register
	 * @param exponent	read exponent from Sensor register
	 * @return
	 */
	float calculateLux(uint8_t mantissa,uint8_t exponent);

	/**
	 * @brief Set the integration time for Lux Measurements internally of the MAX44009
	 * according to its MAX44009Config
	 */
	void setIntegrationTime();

	/**
	 * @brief Set the MAX44009 lux measurements ContinousMode internally of the MAX44009
	 * according to its MAX44009Config
	 */
	void setContinousMode();

	/**
	 * @brief Set the MAX44009 lux measurements ManualConfig internally of the MAX44009
	 * according to its MAX44009Config
	 */
	void setManualConfig();

	/**
	 * @brief Set the I2C device that communicates with MAX44009
	 * @param i2c i2c device that communicates with MAX44009
	 */
	void setI2CRT(I2C_RT* i2c);


	/**
	 * @brief Configure MAX44009 interrupts internally
	 * according to its MAX44009Config
	 */
	void configureInterrupts();

	/**
	 * @brief Configure MAX44009 upper Lux Threshold that triggers an Interrupt
	 * according to its MAX44009Config
	 */
	void setUpperThreshold();

	/**
	 * @brief Configure MAX44009 lower Lux Threshold that triggers an Interrupt
	 * according to its MAX44009Config
	 */
	void setLowerThreshold();
};

#endif /* APP_MAX44009_H_ */
