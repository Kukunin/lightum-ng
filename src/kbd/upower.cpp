#include "upower.h"

#include <cstdio>

using namespace Keyboard;

const char * UPower::busName = "org.freedesktop.UPower";
const char * UPower::objectPath = "/org/freedesktop/UPower/KbdBacklight";
const char * UPower::interface = "org.freedesktop.UPower.KbdBacklight";

UPower::UPower()
	: DBus(G_BUS_TYPE_SYSTEM)
{

}

UPower::~UPower() {

}

int UPower::backlight() {
	GVariant *res = query(
			busName,
			objectPath,
			interface,
			"GetBrightness",
			NULL);

	if ( res == NULL ) {
		return -1;
	}

	int backlight;
	g_variant_get(res, "(i)", &backlight);
	g_variant_unref( res );

	return backlight;
}

void UPower::backlight(int backlight) {
	GVariant *res = query(
			busName,
			objectPath,
			interface,
			"SetBrightness",
			g_variant_new("(i)",backlight));

	if ( !res == NULL ) {
		g_variant_unref( res );
	}
}

bool UPower::isWorking() {
	return backlight() != -1;
}

int UPower::weight() {
	return 10;
}

