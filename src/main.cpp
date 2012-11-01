#include "screen/backend.h"
#include "screen/xbacklight.h"
#include "light/backend.h"
#include "light/apple.h"
#include "kbd/backend.h"
#include "kbd/upower.h"

#include <iostream>

int main() {

	Light::Backend *light = new Light::Apple();
	if ( light->isWorking() ) {
		std::cout << "Current light is " << light->light() << std::endl;
	} else {
		std::cerr << "Light backend isn't available" << std::endl;
	}
	delete light;

	Screen::Backend *screen = new Screen::XBacklight();
	if ( screen->isWorking() ) {
		std::cout << "Current backlight is " << screen->backlight() << std::endl;
	} else {
		std::cerr << "Backlight backend isn't available" << std::endl;
	}
	delete screen;

	Keyboard::Backend *kbd = new Keyboard::UPower();
	if ( kbd->isWorking() ) {
		std::cout << "Current keyboard backlight is " << kbd->backlight() << std::endl;
	} else {
		std::cerr << "Keyboard backlight backend isn't available" << std::endl;
	}
	delete kbd;

	return 0;
}
