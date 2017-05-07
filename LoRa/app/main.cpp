#include "Application.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"
#include "Queue.h"
#include "SHT15.h"


int main() {



	Application application;
	application.init(APPLICATION_MODE_3);

//	I2C_RT* i2c = new I2C_RT();

	RawSerial* debugSerial = new RawSerial(USBTX,USBRX);

	debugSerial->printf("SHT TEST\n");
//	SHTx::SHT15* sht15 = new SHTx::SHT15(I2C_SDA,I2C_SCL);
//	sht15->reset();


    while (true) {
//    	sht15->start();
//    	sht15->sendByte(SHT11_TEMP);
//    	sht15->resetInterface();
//    	sht15->sendByte(SHT11_TEMP);
//    	debugSerial->baud(BAUD_USB);
//		debugSerial->format(8,SerialBase::None,1);
//
//    	sht15->update();
//    	sht15->setScale(false);
//    	float temperature = sht15->getTemperature();
//    	float humidity = sht15->getHumidity();

//

//    	debugSerial->printf("temperature: %f °C \n", temperature);
//    	debugSerial->printf("humidity: %f % \n", humidity);
//    	debugSerial->printf("\n");
//    	osDelay(1000);
//    	sleep();
    }

   return 0;
}



