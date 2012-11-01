#include "screen/backend.h"
#include "screen/xbacklight.h"
#include "light/backend.h"
#include "light/apple.h"
#include "kbd/backend.h"
#include "kbd/upower.h"

#include <cstdio>

int main() {

	Light::Backend *light = new Light::Apple();
	if ( light->isWorking() ) {
		printf("Current light is %d\n",light->light());
	} else {
		fprintf(stderr, "Light backend isn't available");
	}
	delete light;

	Screen::Backend *screen = new Screen::XBacklight();
	if ( screen->isWorking() ) {
		printf("Current backlight is %d\n",screen->backlight());
	} else {
		fprintf(stderr, "Backlight backend isn't available");
	}
	delete screen;

	Keyboard::Backend *kbd = new Keyboard::UPower();
	if ( kbd->isWorking() ) {
		printf("Current keyboard backlight is %d\n",kbd->backlight());
	} else {
		fprintf(stderr, "Light backend isn't available");
	}
	delete kbd;

	return 0;
}
