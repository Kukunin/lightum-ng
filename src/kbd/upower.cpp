#include "upower.h"

#include <cstdio>

using namespace Keyboard;

UPower::UPower()
	: DBus(G_BUS_TYPE_SYSTEM, "org.freedesktop.UPower","/org/freedesktop/UPower/KbdBacklight","org.freedesktop.UPower.KbdBacklight")
{

}

UPower::~UPower() {

}

int UPower::backlight() {
	GVariant *res = query("GetBrightness", NULL );

	if ( res == NULL ) {
		return -1;
	}

	int backlight;
	g_variant_get(res, "(i)", &backlight);
	g_variant_unref( res );

	return backlight;
}

void UPower::backlight(int backlight) {
	GVariant *res = query("SetBrightness", g_variant_new("(i)",backlight));

	if ( res != NULL ) {
		g_variant_unref( res );
	}
}

bool UPower::isWorking() {
	return backlight() != -1;
}

int UPower::weight() {
	return 10;
}

