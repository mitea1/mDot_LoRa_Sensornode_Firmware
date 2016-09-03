/*
 * BME280.h
 *
 *  Created on: 18.05.2016
 *      Author: Adrian
 */
#include <stdint-gcc.h>
#include "I2C_RT.h"
#include "BME280Config.h"

#ifndef APP_BME280_H_
#define APP_BME280_H_


#define BME280_SENSOR_ADDRESS 		0b11101100	/**< Sensor address */
#define BME280_SENSOR_ID			0xD0		/**< ID of BMP280 */
#define BME280_SENSOR_RESET			0xE0		/**< Reset sensor */
#define BME280_SENSOR_CTRL_HUM		0xF2		/**<  */
#define BME280_SENSOR_STATUS		0xF3		/**<  */
#define BME280_SENSOR_CTRL_MEAS		0xF4		/**<  */
#define BME280_SENSOR_CONFIG		0xF5		/**<  */
#define BME280_SENSOR_PRESS_MSB		0xF7		/**< MSB of pressure value */
#define BME280_SENSOR_PRESS_LSB		0xF8		/**< LSB of pressure value */
#define BME280_SENSOR_PRESS_XLSB	0xF9		/**< xtra-LSB of pressure value */
#define BME280_SENSOR_TEMP_MSB		0x00FA		/**< MSB of temperature value */
#define BME280_SENSOR_TEMP_LSB		0x00FB		/**< LSB of temperature value */
#define BME280_SENSOR_TEMP_XLSB		0x00FC		/**< xtra-LSB of temperature value */
#define BME280_SENSOR_HUM_MSB		0xFD		/**< MSB of humidity value */
#define BME280_SENSOR_HUM_LSB		0xFE		/**< xtra-LSB of humidity value */


#define BME280_digT1_LSB			0x88		/**< Trimming parameter for temperature */
#define BME280_digT1_MSB			0x89		/**< Trimming parameter for temperature */
#define BME280_digT2_LSB			0x8A		/**< Trimming parameter for temperature */
#define BME280_digT2_MSB			0x8B		/**< Trimming parameter for temperature */
#define BME280_digT3_LSB			0x8C		/**< Trimming parameter for temperature */
#define BME280_digT3_MSB			0x8D		/**< Trimming parameter for temperature */

#define BME280_digP1_LSB			0x8E		/**< Trimming parameter for pressure */
#define BME280_digP1_MSB			0x8F		/**< Trimming parameter for pressure */
#define BME280_digP2_LSB			0x90		/**< Trimming parameter for pressure */
#define BME280_digP2_MSB			0x91		/**< Trimming parameter for pressure */
#define BME280_digP3_LSB			0x92		/**< Trimming parameter for pressure */
#define BME280_digP3_MSB			0x93		/**< Trimming parameter for pressure */
#define BME280_digP4_LSB			0x94		/**< Trimming parameter for pressure */
#define BME280_digP4_MSB			0x95		/**< Trimming parameter for pressure */
#define BME280_digP5_LSB			0x96		/**< Trimming parameter for pressure */
#define BME280_digP5_MSB			0x97		/**< Trimming parameter for pressure */
#define BME280_digP6_LSB			0x98		/**< Trimming parameter for pressure */
#define BME280_digP6_MSB			0x99		/**< Trimming parameter for pressure */
#define BME280_digP7_LSB			0x9A		/**< Trimming parameter for pressure */
#define BME280_digP7_MSB			0x9B		/**< Trimming parameter for pressure */
#define BME280_digP8_LSB			0x9C		/**< Trimming parameter for pressure */
#define BME280_digP8_MSB			0x9D		/**< Trimming parameter for pressure */
#define BME280_digP9_LSB			0x9E		/**< Trimming parameter for pressure */
#define BME280_digP9_MSB			0x9F		/**< Trimming parameter for pressure */

#define BME280_digH1_LSB			0xA1		/**< Trimming parameter for humidity */
#define BME280_digH2_LSB			0xE1		/**< Trimming parameter for humidity */
#define BME280_digH2_MSB			0xE2		/**< Trimming parameter for humidity */
#define BME280_digH3_LSB			0xE3		/**< Trimming parameter for humidity */
#define BME280_digH4_MSB			0xE4		/**< Trimming parameter for humidity */
#define BME280_digH4_LSB			0xE5		/**< Trimming parameter for humidity */
#define BME280_digH5_LSB			0xE6		/**< Trimming parameter for humidity */
#define BME280_digH5_MSB			0xE5		/**< Trimming parameter for humidity */
#define BME280_digH6_LSB			0xE7		/**< Trimming parameter for humidity */

class BME280 {
public:
	BME280(I2C_RT*);
	virtual ~BME280();
	void init(BME280_MODE);
	void setI2C(I2C_RT*);


	/**
	 * @brief Gets the temperature in °C
	 * @return temperature in °C
	 */
	float getTemperatureFloat();

	/**
	 * @brief Gets the pressure in hPa
	 * @return pressure in hPa
	 */
	float getPressureFloat();

	/**
	 * @brief Gets the humidity in %
	 * @return humidity in %
	 */
	float getHumidityFloat();

private:
	I2C_RT* i2c;
	BME280Config* config;

	uint16_t digT1;
	int16_t digT2;
	int16_t digT3;
	uint8_t digH1;
	int16_t digH2;
	uint8_t digH3;
	int16_t digH4;
	int16_t digH5;
	int8_t digH6;
	uint16_t digP1;
	int16_t digP2;
	int16_t digP3;
	int16_t digP4;
	int16_t digP5;
	int16_t digP6;
	int16_t digP7;
	int16_t digP8;
	int16_t digP9;

	/**
	 * Converts a raw measured humidity value in to an exact humidity value. The algorithm
	 * was defined by Bosch itself
	 * @param humidity_raw the raw measured humidity value
	 * @param temperature_fine the exact temperature value
	 * @return an exact humidity value
	 */
	int32_t compensateHumidity(int32_t humidity_raw, int32_t temperature_fine);

	/**
	 * Converts a raw measured pressure value in to an exact pressure value. The algorithm
	 * was defined by Bosch itself
	 * @param pressure_raw the raw measured pressure value
	 * @param temperature_fine the exact temperature value
	 * @return an exact pressure value
	 */
	int64_t compensatePressure(int32_t pressure_raw, int32_t temperature_fine);

	/**
	 * Converts a raw measured temperature value in to an exact temperature value. The algorithm
	 * was defined by Bosch itself
	 * @param temperatur_raw the raw measured temperature value
	 * @return an exact temperature value
	 */
	int32_t compensateTemperature(int32_t temperature_raw);


	/**
	 * @brief Reads the trim Values that are used for calculation the exact Humidity by the compensateHumidity() Method from
	 * the Sensor Registers and stores them
	 */
	void getTrimValuesHumidity();

	/**
	 * @brief Reads the trim Values that are used for calculation the exact Pressure by the compensatePressure() Method from
	 * the Sensor Registers and stores them
	 */
	void getTrimValuesPressure();

	/**
	 * @brief Reads the trim Values that are used for calculation the exact Temperature by the compensateTemperature() Method from
	 * the Sensor Registers and stores them
	 */
	void getTrimValuesTemperature();


	/**
	 * @brief sets the Sensor in a special low Power Mode that is optimized for wheater Monitoring
	 */
	void setWeatherMonitoringMode();

	/**
	 * @brief sets the Oversampling for Temperature Measurements
	 */
	void setOversamplingTemperature(uint8_t overSamplingTemperature);

	/**
	 * @brief sets the Oversampling for Pressure Measurements
	 */
	void setOversamplingPressure(uint8_t overSamplingPressure);

	/**
	 * @brief sets the Oversampling for Humidity Measurements
	 */
	void setOversamplingHumidity(uint8_t overSamplingHumidity);

	/**
	 * @brief sets the internal Sensor Mode inside the CTRL_MEAS Register
	 */
	void setMode(uint8_t desiredMode);


	/**
	 * Get the raw Value of Humidity from the registers. This Value later needs to be processed
	 * by the compensateHumidity() Method to get the exact Humidity
	 * @return raw Humidity Value
	 */
	uint32_t getHumidity();

	/**
	 * Get the raw Value of Pressure from the registers. This Value later needs to be processed
	 * by the compensatePressure() Method to get the exact Pressure
	 * @return raw Pressure Value
	 */
	uint32_t getPressure();

	/**
	 * Get the raw Value of Temperature from the registers. This Value later needs to be processed
	 * by the compensateTemperature() Method to get the exact Temperature
	 * @return raw Temperature Value
	 */
	int32_t getTemperature();

};

#endif /* APP_BME280_H_ */
