#include "screen/backend.h"
#include "light/backend.h"
#include "kbd/backend.h"
#include "backendmanager.h"

#include <iostream>

int main() {

	try {
		Core::BackendManager backendManager;
		auto light = backendManager.getBackend();
		// if ( light != NULL ) {
		// 	std::cout << "Current light is " << light->light() << std::endl;
		// } else {
		// 	std::cerr << "Light backend isn't available" << std::endl;
		// }

		// Screen::Backend screen = Core::BackendManager::getInstance()->getScreenBackend();
		// if ( screen != NULL ) {
		// 	std::cout << "Current backlight is " << screen.backlight() << std::endl;
		// } else {
		// 	std::cerr << "Any backlight backend isn't available" << std::endl;
		// }

		// Keyboard::Backend kbd = Core::BackendManager::getInstance()->getKbdBackend();
		// if ( kbd != NULL ) {
		// 	std::cout << "Current keyboard backlight is " << kbd.backlight() << std::endl;
		// } else {
		// 	std::cerr << "Keyboard backlight backend isn't available" << std::endl;
		// }
	} catch( const char * str) {

	}

	return 0;
}
