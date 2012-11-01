#include "screen/backend.h"
#include "screen/xbacklight.h"

#include <cstdio>

int main() {

	Screen::Backend *screen = new Screen::XBacklight();

	if ( screen->isWorking() ) {
		printf("Current backlight is %d\n",screen->backlight());
	}

	delete screen;

	return 0;
}
