/**
 * @file TaksHumidity.h
 *
 * @author Adrian
 * @date 30.05.2016
 *

 */
#include "BME280.h"
#include "BME280HumidityMessage.h"
#include "main.h"
#include "Task.h"

#ifndef TASKHUMIDITY_H_
#define TASKHUMIDITY_H_

/**
 * @class TaskHumidity
 * @brief This TaskHumidity Class handles the humidity measurement using the BME280.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskHumidity : public Task {

public:
	TaskHumidity(BME280*,Mutex*, Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>*);
	TaskHumidity(BME280*,Mutex*,Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskHumidity();


private:

	rtos::Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queue;

	BME280* bme280;
	BME280_MODE bme280Mode;

	/**
	 * @brief A thread safe method that measures the humidity. After measuring the humidity
	 * it stores the humidity value inside a BME280HumidityMessage
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueHumidity the queue where the BME280Humidity will be stored
	 */
	void setQueue(Queue<BME280HumidityMessage,HUMIDITY_QUEUE_LENGHT>* queueHumdity);

};


#endif /* TASKHUMIDITY_H_ */
