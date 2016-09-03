/**
 * @file I2C_RT.h
 *
 * @author Adrian
 * @date 19.05.2016
 */

#ifndef APP_I2C_RT_H_
#define APP_I2C_RT_H_

#include <I2C.h>
#include <rtos.h>


/**
 * @class I2C_RT
 * @brief Controls the I2C device of the mDot. mbed::I2C functionality is wrapped
 * inside it's methods. It's possible to wrap other I2C functionality from different Libraries
 * or write an own implementation.
 */
class I2C_RT{
public:
	I2C_RT();
	virtual ~I2C_RT();

	/**
	 * @brief Reads data from a specific register
	 * @param address		address of the I2C Slave device
	 * @param reg			register from which the data has to be read
	 * @param twoBytes		defines if two Bytes at once has to be read
	 * @param readData		storage for the read Data
	 * @param dataLength	length of the storage in bytes
	 */
	void read_RT(uint8_t address, uint16_t reg, bool twoBytes, uint8_t* readData, uint8_t dataLength);

	/**
	 * @brief Write data to a specific register
	 * @param address 		address of the I2C Slave device
	 * @param reg			register where the data has to be write
	 * @param twoBytes		defines if two bytes at once has to be write
	 * @param dataToWrite	the actual data that has to be written
	 * @param dataLenght	the length of the data in bytes
	 */
	void write_RT(uint8_t address,uint16_t reg, bool twoBytes ,uint8_t* dataToWrite ,uint8_t dataLenght);

private:



};

#endif /* APP_I2C_RT_H_ */
