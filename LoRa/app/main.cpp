#include "Application.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"
#include "Queue.h"


int main() {

	Application application;
	application.init(APPLICATION_MODE_2);

    while (true) {
    	sleep();
    }

    return 0;
}
