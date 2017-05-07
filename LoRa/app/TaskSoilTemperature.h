/*
 * TaskSoilMeasurement.h
 *
 *  Created on: 09.01.2017
 *      Author: Adrian
 */
#include "SHT15.h"
#include "main.h"
#include "Task.h"

#ifndef APP_TASKSOILMEASUREMENT_H_
#define APP_TASKSOILMEASUREMENT_H_

/**
 * @class TaskSoilMeasurement
 * @brief This TaskSoilMeasurement Class handles the acceleration measurement using the SHT15.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskSoilTemperature : public Task {
public:
	TaskSoilTemperature(SHTx::SHT15*, Mutex*,
			Queue<SHT15SoilTemperatureMessage,SOIL_TEMPERATURE_QUEUE_LENGHT>*);
	TaskSoilTemperature(SHTx::SHT15*, Mutex*,
			Queue<SHT15SoilTemperatureMessage,SOIL_TEMPERATURE_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskSoilTemperature();
private:
	rtos::Queue<SHT15SoilTemperatureMessage,SOIL_TEMPERATURE_QUEUE_LENGHT>* queue;
	SHTx::SHT15* sht15;

	/**
	 * @brief A thread safe method that acquires soil temperature values. After acquiring them
	 *  it stores the data inside a SHT15SoilTemperatureMessage
	 */
	void measure();

	void setQueue(rtos::Queue<SHT15SoilTemperatureMessage,SOIL_TEMPERATURE_QUEUE_LENGHT>* queue);
};

#endif /* APP_TASKSOILMEASUREMENT_H_ */
