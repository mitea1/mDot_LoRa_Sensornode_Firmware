/**
 * @file SI1143Config.h
 *
 * @author Adrian
 * @date 02.06.2016
 *
 */
#include <stdint-gcc.h>

#ifndef APP_SI1143CONFIG_H_
#define APP_SI1143CONFIG_H_

#define SI1143_LED_VOLTAGE_50_MV	0b0001
#define SI1143_LED_VOLTAGE_115_MV	0b0101
#define SI1143_LED_VOLTAGE_185_MV	0b0111
#define SI1143_LED_VOLTAGE_290_MV	0b1010
#define SI1143_LED_VOLTAGE_410_MV	0b1111

#define SI1143_PS1_IRQ_EN_MASK		0x02
#define SI1143_THRESHOLD_1000		0x3E8

/**
 * SI1143 Modes. Modes define sensor functionality
 */
enum SI1143_MODE{
	SI1143_MODE_1,//!< SI1143_MODE_1
	SI1143_MODE_2,//!< SI1143_MODE_2
	SI1143_MODE_3,//!< SI1143_MODE_3
	SI1143_MODE_4 //!< SI1143_MODE_4
};

/**
 * @class SI1143Config
 * @brief A configuration container for the SI1143 Sensor.
 * All its configuration values are stored an held inside
 * this Class. Depending on the SI1143_MODE it sets all the configuration values.
 */
class SI1143Config {
public:
	SI1143Config();
	virtual ~SI1143Config();

	/**
	 * @brief Generates a configuration and sets its value according to the
	 * chosen SI1143_MODE
	 * @param desiredMode the mode to build the configuration according to
	 */
	void build(SI1143_MODE desiredMode);


	/**
	 * @brief Gets the voltage of Led1 from the actual configuration
	 * @return led 1 voltage register value
	 */
	uint8_t getLed1Voltage();

	/**
	 * @brief Gets the interrupt enable from the actual configuration
	 * @return interrupt enable register value
	 */
	uint8_t getInterruptEnable();

	/**
	 * @brief Gets the proximity sensing threshold for led 1
	 * @return proximity sensing threshold for led 1 register value
	 */
	uint8_t getProximitySensing1Threshold();

private:
	uint8_t led1Voltage;
	uint8_t interruptEnable;
	uint16_t proximitySensing1Threshold;


	/**
	 * @brief Sets the register value for the led 1 voltage of the actual configuration
	 * @param ledVoltag register value of the led1 voltage
	 */
	void setLed1Voltage(uint8_t ledVoltage);

	/**
	 * @brief Sets the interrupt enable register value of the actual configuration
	 * @param interruptEnable register value of interrupt enable
	 */
	void setInterruptEnable(uint8_t interruptEnable);

	/**
	 * @brief Sets the proximity sensing threshold register value of the actual configuration
	 * @param thershold register value of the proximity sensing threshold
	 */
	void setProximitySensing1Threshold(uint16_t thershold);
};

#endif /* APP_SI1143CONFIG_H_ */
