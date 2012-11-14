#include "main.h"

#include <iostream>
#include <unistd.h>

using namespace Core;

int main( int argc, char **argv ) {

	try {

		// make sure we are run as a regular user
		if (getuid() == 0 || geteuid() == 0) {
			fprintf(stderr, "lightum must NOT be run as root.\n");
			exit(1);
		}

		//Parse arguments
		std::shared_ptr<Config> config(new Config());
		config->parseArguments(argc, argv);

		//Consider Main class as Loop class
		Main main(config);
		main.loop();
	} catch( std::exception str) {
		std::cerr << "Global expcetion: " << str.what() << std::endl;
	} catch( ... ) {
		std::cerr << "Global error without type" << std::endl;
	}

	return 0;
}

Main::Main( std::shared_ptr<Config> config ) {
	this->config = config;
	mode = 0;

	//Can't work without lightBackend, so let exception threw
	lightBackend = backendManager.getLightBackend();

	try {
		screenBackend = backendManager.getScreenBackend();
		mode = mode | (int) ScreenMode;
	} catch ( std::exception e ) {
		if ( config->verbose() ) {
			std::cerr << e.what() << std::endl;
		}
	}

	try {
		kbdBackend = backendManager.getKbdBackend();
		mode = mode | (int) KeyboardMode;
	} catch ( std::exception e ) {
		if ( config->verbose() ) {
			std::cerr << e.what() << std::endl;
		}
	}

}

Main::~Main() {

}

void Main::loop() {

	while( true ) {

		int light = lightBackend->light();

		if ( config->verbose() ) {
			std::cout << "Tick. Light sensor is " << light << std::endl;
		}

		if ( mode & (int) ScreenMode ) {
			//Make sure, that screen backlight is between min and 100 (max backlight);
			int screen = config->minScreenBacklight() + (light * (100 - config->minScreenBacklight()) / 100);
			screenBackend->backlight(screen);
			if ( config->verbose() ) {
				std::cout << "Screen Backlight is " << screen << std::endl;
			}
		}

		if ( mode & (int) KeyboardMode ) {
			//Make sure, that keyboard backlight is between min and 100 (max backlight);
			int kbd = config->minKeyboardBacklight() + (light * (100 - config->minKeyboardBacklight()) / 100);

			kbdBackend->backlight(kbd);
			if ( config->verbose() ) {
				std::cout << "Keyboard Backlight is " << kbd << std::endl;
			}
		}

		usleep( config->delay() * 1000 );
	}

}
