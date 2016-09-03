/**
 * @file MPU9250Config.h
 *
 * @author Adrian
 * @date 23.05.2016
 *
 */

#include <stdint-gcc.h>

#ifndef APP_MPU9250CONFIG_H_
#define APP_MPU9250CONFIG_H_

#define MPU9250_GYRO_FULL_SCALE_250DPS  0b00
#define MPU9250_GYRO_FULL_SCALE_500DPS  0b01
#define MPU9250_GYRO_FULL_SCALE_1000DPS 0b10
#define MPU9250_GYRO_FULL_SCALE_2000DPS 0b11

#define MPU9250_FULL_SCALE_2G           0b00
#define MPU9250_FULL_SCALE_4G           0b01
#define MPU9250_FULL_SCALE_8G           0b10
#define MPU9250_FULL_SCALE_16G          0b11

#define MPU9250_MAG_16_BIT				0b1
#define MPU9250_MAG_14_BIT				0b0

#define MPU9250_MAG_SINGLE_MEASUREMENT			0b0001
#define MPU9250_MAG_CONTINUOUS_MEASUREMENT_1	0b0010
#define MPU9250_MAG_CONTINUOUS_MEASUREMENT_2	0b0110

//INT_PIN_CFG register masks
#define MPU9250_ACTL_MASK               0x80
#define MPU9250_OPEN_MASK               0x40
#define MPU9250_LATCH_INT_EN_MASK       0x20
#define MPU9250_INT_ANYRD_2CLEAR_MASK   0x10
#define MPU9250_ACTL_FSYNC_MASK         0x08
#define MPU9250_FSYNC_INT_MODE_EN_MASK  0x04
#define MPU9250_BYPASS_EN_MASK          0x02

//INT_ENABLE register masks
#define MPU9250_WOM_EN_MASK             0x40
#define MPU9250_FIFO_OFLOW_EN_MASK      0x10
#define MPU9250_FSYNC_INT_EN_MASK       0x08
#define MPU9250_RAW_RDY_EN_MASK         0x01

#define MPU9250_WOM_THRESHOLD_1020_MG	0xFF
#define MPU9250_WOM_THRESHOLD_500_MG	0x7D
#define MPU9250_WOM_THRESHOLD_250_MG	0xFA

/**
 * MPU9250 Modes. Modes define Sensor functionality
 */
enum MPU9250_MODE{
	MPU9250_MODE_1,//!< MPU9250_MODE_1
	MPU9250_MODE_2,//!< MPU9250_MODE_2
	MPU9250_MODE_3,//!< MPU9250_MODE_3
	MPU9250_MODE_4 //!< MPU9250_MODE_4
};

/**
 * @class MPU9250Config
 * @brief A configuration container for the MPU9250 Sensor.
 * All its configuration values are stored an held inside
 * this Class. Depending on the MPU9250_MODE it sets all the configuration values.
 */
class MPU9250Config {
public:
	MPU9250Config();
	virtual ~MPU9250Config();

	/**
	 * @brief Generates a configuration according to the chosen MPU9250_MODE
	 * @param desiredMode the mode to build the configuration according to
	 */
	void build(MPU9250_MODE desiredMode);


	/**
	 * @brief Gets the Accelerometer Scale from the actual configuration
	 * @return accelerometer scale
	 */
	uint8_t getAccelerometerScale();

	/**
	 * @brief Gets the Gyroscope Scale from the actual configuration
	 * @return gyroscope scale
	 */
	uint8_t getGyroscopeScale();

	/**
	 * @brief Gets the Magnetometer bit resolution from the actual configuration
	 * @return magnetometer bit resolution
	 */
	uint8_t getMagnetometerBitResolution();

	/**
	 * @brief Gets the Magnetometer measure mode  from the actual configuration
	 * @return magnetometer bit resolution
	 */
	uint8_t getMagnetometerMeasureMode();

	/**
	 * @brief Gets the Acceleration Divider from the actual configuration
	 * @return acceleration divider
	 */
	float getAccelerationDivider();

	/**
	 * @brief Gets the Gyroscope Divider from the actual configuration
	 * @return gyroscope divider
	 */
	float getGyroDivider();

	/**
	 * @brief Gets the Tesla Divider from the actual configuration
	 * @return
	 */
	float getTeslaDivider();


	/**
	 * @brief Gets the Interrupt Pin configuration from the actual configuration
	 * @return interrupt pin configuration
	 */
	uint8_t getInterruptPinConfiguration();

	/**
	 * @brief Gets the Interrupt Enable configuration from the actual configuration
	 * @return interrupt enable configuration
	 */
	uint8_t getInterruptEnableConfiguration();

	/**
	 * @brief Gets the wake on motion threshold value from the actual configuration
	 * @return wake on motion threshold value
	 */
	uint8_t getWakeOnMotionThreshold();

private:
	uint8_t gyroscopeScale;
	uint8_t accelerometerScale;
	uint8_t magnetometerBitResolution;
	uint8_t magnetometerMeasureMode;

	uint8_t interruptPinConfiguration;
	uint8_t interruptEnableConfiguration;

	uint8_t wakeOnMotionThreshold;


	/**
	 * @brief Sets the accelerometer scale of the actual configuration
	 * @param accelerometerScale
	 */
	void setAccelerometerScale(uint8_t accelerometerScale);

	/**
	 * @brief Sets the gyroscope scale of the actual configuration
	 * @param gyroscopeScale
	 */
	void setGyroscopeScale(uint8_t gyroscopeScale);

	/**
	 * @brief Sets the magnetometer bit resolution of the actual configuration
	 * @param magnetometerBitResolution
	 */
	void setMagnetometerBitResolution(uint8_t magnetometerBitResolution);

	/**
	 * @brief Sets the magnetometer measure mode of the actual configuration
	 * @param magnetometerMeasureMode
	 */
	void setMagnetometerMeasureMode(uint8_t meagnetometerMeasureMode);


	/**
	 * @brief Sets the interrupt pin configuration of the actual configuration
	 * @param interruptPinConfiguration
	 */
	void setInterruptPinConfiguration(uint8_t interruptPinConfiguration);

	/**
	 * @brief Sets the interrupt enable configuration of the actual configuration
	 * @param interruptEnableConfiguration
	 */
	void setInterruptEnableConfiguration(uint8_t interruptEnableConfiguration);


	/**
	 * @brief Sets the wake on motion threshold of the actual configuration
	 * @param wakeOnMotionThreshold
	 */
	void setWakeOnMotionThreshold(uint8_t wakeOnMotionThreshold);
};

#endif /* APP_MPU9250CONFIG_H_ */
