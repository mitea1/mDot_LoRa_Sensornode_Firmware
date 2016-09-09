/**
 * @file TaskProximity.h
 *
 * @author Adrian
 * @date 03.06.2016
 *
 */
#include "SI1143.h"
#include "SI1143ProximityMessage.h"
#include "main.h"
#include "Task.h"

#ifndef TASKPROXIMITY_H_
#define TASKPROXIMITY_H_

/**
 * @class TaskProximity
 * @brief This TaskProximity Class handles the proximity measurement using the SI1143.
 * Starting the task using the start() starts the measurement.
 * It can be used alongside with other measurement Tasks inside the mbed::rtos
 * environment. The Task Class basically wraps mbeds Thread functionality.
 */
class TaskProximity : public Task {
public:
	TaskProximity(SI1143*,Mutex*,Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>*);
	TaskProximity(SI1143*,Mutex*,Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskProximity();

private:
	rtos::Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queue;

	SI1143* si1143;

	/**
	 * @brief A thread safe method that acquires data from the gyroscope. After acquiring data from the
	 * it stores the data inside a SI1143ProximityMessage
	 */
	void measure();

	/**
	 * @brief Sets the message Queue of the Task where the measured values will be stored
	 * after the measurement
	 * @param queueProximity the queue where the SI1143ProximityMessage will be stored
	 */
	void setQueue(Queue<SI1143ProximityMessage,PROXIMITY_QUEUE_LENGHT>* queueProximity);

};

#endif /* TASKPROXIMITY_H_ */
