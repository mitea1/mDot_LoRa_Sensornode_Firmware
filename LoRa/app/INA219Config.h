/*
 * INA219Config.h
 *
 *  Created on: 01.11.2016
 *      Author: Adrian
 */
#include <stdint.h>

#ifndef APP_INA219CONFIG_H_
#define APP_INA219CONFIG_H_

/**
 * INA219 Modes. Modes define sensor functionality
 */
enum INA219_MODE{
	INA219_MODE_0,//!< INA219_MODE_0
	INA219_MODE_1,//!< INA219_MODE_0
	INA219_MODE_2,//!< INA219_MODE_0
};

/**
 * @class INA219Config
 * @brief A configuration container for the INA219 Sensor.
 * All its configuration values are stored an held inside
 * this Class. Depending on the INA219_MODE it sets all the configuration values.
 */
class INA219Config {
public:
	INA219Config();
	virtual ~INA219Config();

	/**
	 * @brief Generates a configuration according to the chosen INA219_MODE
	 * @param desiredMode the mode to build the configuration according to
	 */
	void build(INA219_MODE);

	uint8_t getMode();

private:

	uint8_t mode;

	void setMode(uint8_t desiredMode);
};

#endif /* APP_INA219CONFIG_H_ */
