#include "upower.h"

using namespace Keyboard;

UPower::~UPower() {

}
int UPower::backlight() {
	return 1;
}

void UPower::backlight(int backlight) {

}

bool UPower::isWorking() {
	return true;
}

int UPower::weight() {
	return 10;
}
