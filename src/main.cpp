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

		Main main(config);
		main.loop();
		// Core::BackendManager backendManager;
		// try {
		// 	std::unique_ptr<Light::Backend> light = backendManager.getLightBackend();
		// 	std::cout << "Current light is " << light->light() << std::endl;
		// } catch ( const char * str) {
		// 	std::cerr << "Error: " << str << std::endl;
		// }

		// try {
		// 	std::unique_ptr<Screen::Backend> screen = backendManager.getScreenBackend();
		// 	std::cout << "Current backlight is " << screen->backlight() << std::endl;
		// } catch ( const char * str ) {
		// 	std::cerr << "Error:" << str << std::endl;
		// }

		// try {
		// 	std::unique_ptr<Keyboard::Backend> kbd = backendManager.getKbdBackend();
		// 	std::cout << "Current keyboard backlight is " << kbd->backlight() << std::endl;
		// } catch ( const char * str ) {
		// 	std::cerr << "Error:" << str << std::endl;
		// }
	} catch( std::string str) {
		std::cerr << "Global error: " << str << std::endl;
	} catch( std::exception str) {
		std::cerr << "Global expcetion" << str.what() << std::endl;
	} catch( ... ) {
		std::cerr << "Global error without type" << std::endl;
	}

	return 0;
}

Main::Main( std::shared_ptr<Config> config ) {
	this->config = config;
}

Main::~Main() {

}

void Main::loop() {

}
