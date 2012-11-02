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
	return getInt("GetBrightness");
}

void UPower::backlight(int backlight) {
	exec("SetBrightness", g_variant_new("(i)",backlight));
}

bool UPower::isWorking() {
	return backlight() != -1;
}

int UPower::weight() {
	return 10;
}

Backend* UPower::create() {
	return new UPower();
}
