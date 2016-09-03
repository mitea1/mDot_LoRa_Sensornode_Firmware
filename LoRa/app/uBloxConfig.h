/**
 * @file uBloxConfig.h
 *
 * @author Adrian
 * @date 30.05.2016
 *
 */
#include <string>
#include <map>
#include <vector>
#include "stdint-gcc.h"
#ifndef UBLOXCONFIG_H_
#define UBLOXCONFIG_H_


#define UBLOX_DISABLE_ALL_STRING		"DISABLE ALL STRINGS"
#define UBLOX_ENABLE_POSLLH_STRING		"ENABLE POSLLH STRING"
#define UBLOX_GNSS_ON					"GNSS ON"
#define UBLOX_GNSS_OFF					"GNSS OFF"
#define UBLOX_CONTINUOUS_MODE			"CONTINUOUS MODE"
#define UBLOX_POWER_SAVE_MODE			"POWER SAVE MODE"
#define UBLOX_ECO_MODE					"POWER SAVE MODE"

/**
 * uBlox Modes. Modes define Sensor functionality
 */
enum uBLOX_MODE{
	uBLOX_MODE_0,//!< uBLOX_MODE_0
	uBLOX_MODE_1,//!< uBLOX_MODE_1
	uBLOX_MODE_2,//!< uBLOX_MODE_2
	uBLOX_MODE_3,//!< uBLOX_MODE_3
};

/**
 * @class uBloxConfig
 * @brief A configuration container for the uBlox.
 * All its configuration values are stored an held inside
 * this Class. Depending on the uBLOX_MODE it sets all the configuration values.
 */
class uBloxConfig {
public:
	uBloxConfig();
	virtual ~uBloxConfig();

	/**
	 * @brief Generates a configuration according to the chosen uBLOX_MODE. More exactly it builds
	 * the strings that have to be sent at the initialization of the uBlox to run the uBlox to
	 * run it in a specific configuration
	 * @param desiredMode the mode to build the configuration according to
	 */
	void build(uBLOX_MODE);

	std::vector< std::vector<uint8_t> > getInitialConfigurationString();
private:

	std::map<std::string,std::vector<uint8_t> > configCommands;
	std::vector< std::vector<uint8_t> > initialCommands;

	/**
	 * @brief Connects a command and its string that consists of Bytes
	 * @param command a command string describing the command
	 * @param string the content of the command
	 */
	void connectCommandAndString(std::string command, uint8_t* string, uint8_t stringSize);


};

#endif /* UBLOXCONFIG_H_ */
