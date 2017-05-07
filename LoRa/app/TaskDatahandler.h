/**
 * @file TaskDatahandler.h
 *
 * @author Adrian
 * @date 27.05.2016
 *
 */

#ifndef TASKDATAHANDLER_H_
#define TASKDATAHANDLER_H_

#include <Thread.h>
#include <Queue.h>
#include <Mutex.h>
#include "LoRa.h"
#include "MAX44009Message.h"
#include "BME280TemperatureMessage.h"
#include "BME280PressureMessage.h"
#include "BME280HumidityMessage.h"
#include "CommandMessage.h"
#include "main.h"

/**
 * @class TaskGyroscope
 * @brief This TaskGyroscope Class handles all the acquired data from other Tasks
 * that measure data using the different sensors of Sensbert.
 * Starting the task using the start() starts the handling of the Data. The Task looks
 * for queues that contains data and forwards the data from the queues via LoRa.
 * The Task Class basically wraps mbeds Thread functionality.
 */
class TaskDatahandler {
public:
	TaskDatahandler(LoRa*,Mutex*,QueueBundle,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskDatahandler();


	/**
	 * @brief Starts the task by building it and connecting a callback function to
	 * the mbed::Thread
	 * @return
	 */
	osStatus start();

	/**
	 * @brief Stops the task. Should only be used after start() was used
	 * @return
	 */
	osStatus stop();


	/**
	 * @brief Gets the actual state of the Task either RUNNING or SLEEPING
	 * @return
	 */
	TASK_STATE getState();


	/**
	 * @brief Set a serial interface thats used for debugging the datastream which
	 * will be sent via LoRa and to show data handling relevant information
	 * @param debugSerial the Serial interface used to show information
	 */
	void setDebugSerial(RawSerial* debugSerial);

	/**
	 * @brief Sets the LoRa interface thats used to forward acquired data form other
	 * Tasks.
	 * @param lora the lora interface that should be used to forward data via LoRa
	 */
	void setLoRa(LoRa* lora);

private:
	Thread* thread;
	QueueBundle queueBundle;
	RawSerial* debugSerial;
	LoRa* lora;
	Mutex* mutexLora;

	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	osEvent lightMeasureEvent;
	osEvent temperatureMeasureEvent;
	osEvent pressureMeasureEvent;
	osEvent humidityMeasureEvent;
	osEvent accelerationMeasureEvent;
	osEvent gyroscopeMeasureEvent;
	osEvent teslaMeasureEvent;
	osEvent proximityMeasureEvent;
	osEvent gpsMeasureEvent;
	osEvent soilTemperatureMeasureEvent;
	osEvent soilMoistureMeasureEvent;
	osEvent loraMeasureEvent;
	osEvent powerMeasureEvent;

	CommandMessage commandMessage;


	/**
	 * @brief A Callback function thats called by the mbed::Thread of this TaskClass
	 * @param
	 */
	static void callBack(void const *);

	/**
	 * @brief Attaches the idle_hook for this task
	 * @param
	 */
	void attachIdleHook(void (*fptr) (void));

	/**
	 * @brief A method thats handling the data which was acquired and stored into
	 * Message Queues
	 */
	void handleData();

	/**
	 * @brief Checks all queues for available data and gets it.
	 */
	void getMessagesFromSensorQueues();

	/**
	 * @brief Forwards all data which was in a Message Queue and
	 * via LoRa
	 */
	void forwardSensorMessages();

	/**
	 * @brief Forwards the received commands from LoRa to a CommandMessageQueue
	 */
	void forwardCommandMessages();

	/**
	 * @brief Sets the mutex for accessing and using the LoRa interface
	 * @param mutexLoRa
	 */
	void setMutex(Mutex* mutexLoRa);

	/**
	 * @brief Sets the bundle that holds all other queues that can store
	 * measured sensor data
	 * @param queueBundle bundle that holds all the other queues
	 */
	void setQueueBundle(QueueBundle queueBundle);

	/**
	 * @brief Sets the priority of the Task
	 * @param priority priority of the Task
	 */
	void setPriority(osPriority priority);

	/**
	 * @brief Sets the size of the Task
	 * @param stackSize the stack size in Bytes
	 */
	void setStackSize(uint32_t stackSize);

	/**
	 * @brief Sets the stack pointer of for the task stack
	 * @param stackPointer
	 */
	void setStackPointer(unsigned char* stackPointer);

	/**
	 * @brief Sets the actual state of the Task.
	 * @param taskState either RUNNING or SLEEPING
	 */
	void setState(TASK_STATE taskState);

	void appendLoRaMessage(void* message);

};

#endif /* TASKDATAHANDLER_H_ */
