#include "screen/backend.h"
#include "screen/xbacklight.h"
#include "light/backend.h"
#include "light/apple.h"

#include <cstdio>

int main() {

	Screen::Backend *screen = new Screen::XBacklight();

	if ( screen->isWorking() ) {
		printf("Current backlight is %d\n",screen->backlight());
	} else {
		fprintf(stderr, "Backlight backend isn't available");
	}

	Light::Backend *light = new Light::Apple();

	if ( light->isWorking() ) {
		printf("Current light is %d\n",light->light());
	} else {
		fprintf(stderr, "Light backend isn't available");
	}

	delete screen;
	delete light;

	return 0;
}
