#include "screen/backend.h"
#include "light/backend.h"
#include "kbd/backend.h"
#include "backendmanager.h"

#include <iostream>

int main() {

	try {
		Core::BackendManager backendManager;
		try {
			std::unique_ptr<Light::Backend> light = backendManager.getLightBackend();
			std::cout << "Current light is " << light->light() << std::endl;
		} catch ( const char * str) {
			std::cerr << "Error: " << str << std::endl;
		}

		try {
			std::unique_ptr<Screen::Backend> screen = backendManager.getScreenBackend();
			std::cout << "Current backlight is " << screen->backlight() << std::endl;
		} catch ( const char * str ) {
			std::cerr << "Error:" << str << std::endl;
		}

		try {
			std::unique_ptr<Keyboard::Backend> kbd = backendManager.getKbdBackend();
			std::cout << "Current keyboard backlight is " << kbd->backlight() << std::endl;
		} catch ( const char * str ) {
			std::cerr << "Error:" << str << std::endl;
		}
	} catch( const char * str) {
		std::cerr << "Global error: " << str << std::endl;

	}

	return 0;
}
