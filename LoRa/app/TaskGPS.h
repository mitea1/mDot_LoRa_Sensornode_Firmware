/**
 * @file TaskGPS.h
 *
 * @author Adrian
 * @date 30.05.2016
 *
 */
#include "uBlox.h"
#include "UBloxGPSMessage.h"
#include "main.h"
#include "Task.h"

#ifndef TASKGPS_H_
#define TASKGPS_H_

/**
 * @class TaskGPS
 * @brief This TaskGPS Class handles the GPS measurement using the uBlox.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskGPS : public Task {
public:
	TaskGPS(uBlox*,Mutex*, Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>*);
	TaskGPS(uBlox*,Mutex*,Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskGPS();

private:
	rtos::Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queue;
	uBlox* mUBlox;
	uBLOX_MODE uBloxMode;


	/**
	 * @brief A thread safe method that acquires GPS values. After acquiring GPS Data
	 *  it stores the data inside a uBLoxGPSMessage
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the acquired data will be stored
	 * after the acquisition
	 * @param queueGps the queue where the MPU9250AccelerationMessage will be stored
	 */
	void setQueue(Queue<UBloxGPSMessage,GPS_QUEUE_LENGHT>* queueGps);

};

#endif /* TASKGPS_H_ */
