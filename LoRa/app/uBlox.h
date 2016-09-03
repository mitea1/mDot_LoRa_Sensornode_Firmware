/**
 * @file uBlox.h
 *
 * @author Adrian
 * @date 16.05.2016
 *
 */

#include <RawSerial.h>
#include <rtos.h>
#include "Decoder.h"
#include "uBloxConfig.h"

#ifndef APP_UBLOX_H_
#define APP_UBLOX_H_

/**
 * @class uBlox
 * @brief Provides Functionality to control the uBlox
 */
class uBlox {
public:
	uBlox(mbed::RawSerial*);
	virtual ~uBlox();

	/**
	 * @brief Initializes the uBlox according to the desired uBLOX_MODE
	 * @param desiredMode the desired Mode depending on which the uBlox has to be
	 * configured
	 */
	void init(uBLOX_MODE);

	/**
	 * @brief Gets the GPS Time of Week in ms
	 */
	unsigned long getTimeOfWeekMs();

	/**
	 * @brief Gets the decoded Latitude of the GPS Coordinate
	 * @return
	 */
	float getLatitude();

	/**
	 * @brief Gets the decoded Longitude of the GPS Coordinate
	 * @return
	 */
	float getLongitude();

	/**
	 * @brief Gets the decoded height above ellipsoid of the GPS Coordinate
	 * @return
	 */
	signed long getHeightAboveEllipsoid();

	/**
	 * @brief Gets the decoded height above mean sea level of the GPS Coordinate
	 * @return
	 */
	signed long getHeightAboveMeanSeaLevel();

	/**
	 * @brief Gets the decoded horizontal accuracy of the GPS Coordinate measurement
	 * @return
	 */
	unsigned long getHorizontalAccuracyEstimate();

	/**
	 * @brief Gets the decoded vertical accuracy of the GPS Coordinate measurment
	 * @return
	 */
	unsigned long getVerticalAccuracyEstimate();

private:
	Decoder* decoder;
	mbed::RawSerial* serial;

	uBloxConfig* config;

	/**
	 * @brief Sends a Configuration String via the uart interface of the uBlox
	 * @param configurationString
	 */
	void sendConfigurationString(std::vector<uint8_t> configurationString);

};

#endif /* APP_UBLOX_H_ */
