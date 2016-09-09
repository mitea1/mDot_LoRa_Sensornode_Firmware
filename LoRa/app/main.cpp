#include "Application.h"
#include "ApplicationConfig.h"
#include "UARTTunnel.h"

int main() {

	Application application;
	application.init(APPLICATION_MODE_1);

    while (true) {
    	sleep();
    }

    return 0;
}
