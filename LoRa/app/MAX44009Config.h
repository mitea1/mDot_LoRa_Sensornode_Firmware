/**
 * @file MAX44009Config.h
 *
 * @author Adrian
 * @date 25.05.2016
 *
 */
#include <stdint-gcc.h>
#ifndef APP_MAX44009CONFIG_H_
#define APP_MAX44009CONFIG_H_

#define MAX_44009_CONTINOUS_MODE_ON			0b1
#define MAX_44009_CONTINOUS_MODE_OFF		0b0
#define MAX_44009_MANUAL_CONFIG_ON			0b1
#define MAX_44009_MANUAL_CONFIG_OFF			0b0

//Integration Times
#define MAX_44009_INTEGRATION_TIME_800_MS	0b000
#define MAX_44009_INTEGRATION_TIME_400_MS	0b001
#define MAX_44009_INTEGRATION_TIME_200_MS	0b010
#define MAX_44009_INTEGRATION_TIME_100_MS	0b011
#define MAX_44009_INTEGRATION_TIME_50_MS	0b100
#define MAX_44009_INTEGRATION_TIME_25_MS	0b101
#define MAX_44009_INTEGRATION_TIME_12_5_MS	0b110
#define MAX_44009_INTEGRATION_TIME_6_25_MS	0b111

#define MAX_44009_IRQ_ENABLED				0x1
#define MAX_44009_THRESHOLD_4096_LUX		0xC0

/**
 * MAX44009 Modes
 */
enum MAX44009_MODE{
	MAX44009_MODE_0,//!< MAX44009_MODE_0
	MAX44009_MODE_1,//!< MAX44009_MODE_1
	MAX44009_MODE_2,//!< MAX44009_MODE_2
	MAX44009_MODE_3,//!< MAX44009_MODE_3
	MAX44009_MODE_4,//!< MAX44009_MODE_4
	MAX44009_MODE_5,//!< MAX44009_MODE_5
	MAX44009_MODE_6,//!< MAX44009_MODE_6
};

/**
 * @class MAX44009Config
 * @brief A configuration container for the MAX44009 Sensor.
 * All its configuration values are stored an held inside
 * this Class. Depending on the MAX44009_MODE using
 * as a parameter for the build() method it sets all the configuration values.
 */

class MAX44009Config {
public:
	MAX44009Config();
	MAX44009Config(MAX44009_MODE);
	virtual ~MAX44009Config();

	/**
	 * @brief Generates a configuration according to the chosen MAX44009_MODE
	 * by setting all LoRa Module specific configuration values depending on the chosen MAX44009_MODE
	 * @param desiredMode the mode to build the configuration according to
	 */
	void build(MAX44009_MODE desiredMode);


	/**
	 * @brief Gets the integration Time for Lux Measurements defined in the actual
	 * MAX44009Config
	 * @return
	 */
	uint8_t getIntegrationTime();

	/**
	 * @brief Gets the Continuous Mode for Lux Measurements defined in the actual
	 * MAX44009Config
	 * @return
	 */
	uint8_t getContinousMode();

	/**
	 * @brief Gets the Manual Config for the Sensor defined in the actual
	 * MAX44009Config
	 * @return
	 */
	uint8_t getManualConfig();

	/**
	 * @brief Gets the interrupt Enable Value that has to be written to the MAX44009
	 * according to the actual MAX44009Config
	 * @return
	 */
	uint8_t getInterruptEnable();

	/**
	 * @brief Gets the upper Threshold Value that has to be written to the MAX44009
	 * according to the actual MAX44009Config
	 * @return
	 */
	uint8_t getUpperThreshold();

	/**
	 * @brief Gets the lower Threshold Value that has to be written to the MAX44009
	 * according to the actual MAX44009Config
	 * @return
	 */
	uint8_t getLowerThreshold();

private:
	uint8_t integrationTime;
	uint8_t continousMode;
	uint8_t manualConfig;
	uint8_t interruptEnable;
	uint8_t upperThreshold;
	uint8_t lowerThreshold;

	/**
	 * @brief Sets the integration time value of the MAX44009Config. The value later will be written
	 * inside MAX44009 specific register by MAX44009 itself
	 * @param integrationTime integration Time register value
	 */
	void setIntegrationTime(uint8_t integrationTime);

	/**
	 * @brief Sets the continuous mode value of the MAX44009Config. The value later will be written
	 * inside MAX44009 specific register by MAX44009 itself
	 * @param continuousMode continuous mode register value
	 */
	void setContinousMode(uint8_t continuousMode);

	/**
	 * @brief Sets the continuous mode value of the MAX44009Config. The value later will be written
	 * inside MAX44009 specific register by MAX44009 itself
	 * @param continuousMode continuous mode register value
	 */
	void setManualConfig(uint8_t manualConfig);

	/**
	 * @brief Sets the interrupt enable value of the MAX44009Config. The value later will be written
	 * inside MAX44009 specific register by MAX44009 itself
	 * @param interruptEnable interruptEnable register value
	 */
	void setInterruptEnable(uint8_t interruptEnable);

	/**
	 * @brief Sets the upper threshold value of the MAX44009Config. The value later will be written
	 * inside MAX44009 specific register by MAX44009 itself
	 * @param upperThreshold upper threshold register value
	 */
	void setInterruptUpperThreshold(uint8_t upperThreshold);

	/**
	 * @brief Sets the lower threshold value of the MAX44009Config. The value later will be written
	 * inside MAX44009 specific register by MAX44009 itself
	 * @param upperThreshold upper threshold register value
	 */
	void setInterruptLowerThreshold(uint8_t lowerThreshold);
};

#endif /* APP_MAX44009CONFIG_H_ */
