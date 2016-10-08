/**
 * @file TaskCommandHandler.h
 *
 * @author Adrian
 * @date 11.09.2016
 *
 */

#ifndef TASKCOMMANDHANDLER_H_
#define TASKCOMMANDHANDLER_H_

#include <Thread.h>
#include <Queue.h>
#include <Mutex.h>
#include "LoRa.h"
#include "MAX44009Message.h"
#include "CommandMessage.h"
#include "main.h"

/**
 * @class TaskCommandHandler
 * @brief This TaskCommandHandler Class handles all the received Commands from LoRa
 */
class TaskCommandHandler {
public:

	TaskCommandHandler(Queue<CommandMessage,COMMAND_QUEUE_LENGHT>*,
			osPriority, uint32_t, unsigned char*);
	virtual ~TaskCommandHandler();
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

private:
	Thread* thread;
	RawSerial* debugSerial;
	rtos::Queue<CommandMessage,COMMAND_QUEUE_LENGHT>* queue;

	osPriority priority;
	uint32_t stack_size;
	unsigned char *stack_pointer;

	TASK_STATE state;

	osEvent commandReceiveEvent;


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
	void handleCommands();

	/**
	 * @brief Checks all queues for available data and gets it.
	 */
	void getCommandMessages();

	/**
	 * @brief Processes received commands from command Queue
	 */
	void processCommands();


	/**
	 * @brief Sets the message Queue of the Task where the received commands are stored
	 * after the reception via LoRa
	 * @param queueCommand the queue where the CommandMessage will be stored
	 */
	void setQueue(Queue<CommandMessage,COMMAND_QUEUE_LENGHT>* queueCommand);

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

};

#endif /* TASKCOMMANDHANDLER_H_ */
