#include "Application.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"
#include "Queue.h"
#include "INA219.h"


int main() {

//	Application application;
//	application.init(APPLICATION_MODE_3);

	I2C_RT* i2c = new I2C_RT();
	INA219* ina219 = new INA219(i2c);
	RawSerial* debugSerial = new RawSerial(USBTX,USBRX);


	ina219->setCalibration_16V_400mA();


    while (true) {
    	debugSerial->baud(BAUD_USB);
		debugSerial->format(8,SerialBase::None,1);

    	float shuntVoltage = ina219->getShuntVoltage_mV();
    	float busVoltage = ina219->getBusVoltage_V();
    	float current = ina219->getCurrent_mA();
    	float power = ina219->getPower_mW();

    	debugSerial->printf("Shunt: %f mV \n", shuntVoltage);
    	debugSerial->printf("Bus: %f V \n",busVoltage);
    	debugSerial->printf("Current: %f mA \n",current);
    	debugSerial->printf("Power: %f mW \n",power);
    	debugSerial->printf("\n");
    	osDelay(100);
    }

    return 0;
}
