#include "screen/backend.h"
#include "screen/xbacklight.h"
#include "screen/gnome.h"
#include "screen/kde.h"
#include "light/backend.h"
#include "light/apple.h"
#include "kbd/backend.h"
#include "kbd/upower.h"
#include "backendmanager.h"

#include <iostream>

int main() {

	Light::Backend *light = Core::BackendManager::getInstance()->getLightBackend();
	if ( light != NULL ) {
		std::cout << "Current light is " << light->light() << std::endl;
	} else {
		std::cerr << "Light backend isn't available" << std::endl;
	}
	delete light;

	Screen::Backend *screen = Core::BackendManager::getInstance()->getScreenBackend();
	if ( screen != NULL ) {
		std::cout << "Current backlight is " << screen->backlight() << std::endl;
	} else {
		std::cerr << "Any backlight backend isn't available" << std::endl;
	}
	delete screen;

	Keyboard::Backend *kbd = Core::BackendManager::getInstance()->getKbdBackend();
	if ( kbd != NULL ) {
		std::cout << "Current keyboard backlight is " << kbd->backlight() << std::endl;
	} else {
		std::cerr << "Keyboard backlight backend isn't available" << std::endl;
	}
	delete kbd;

	return 0;
}
