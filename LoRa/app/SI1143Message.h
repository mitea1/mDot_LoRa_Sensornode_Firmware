/*
 * SI1143Message.h
 *
 *  Created on: 02.06.2016
 *      Author: Adrian
 */

#ifndef APP_SI1143MESSAGE_H_
#define APP_SI1143MESSAGE_H_

#include "SensorMessage.h"

class SI1143Message: public SensorMessage {
public:
	SI1143Message();
	virtual ~SI1143Message();
};

#endif /* APP_SI1143MESSAGE_H_ */
