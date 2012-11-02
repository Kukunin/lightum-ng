#include "kde.h"

using namespace Screen;


KDE::KDE()
	: DBus(G_BUS_TYPE_SESSION, "org.kde.Solid.PowerManagement", "/org/kde/Solid/PowerManagement", "org.kde.Solid.PowerManagement")
{

}

KDE::~KDE() {

}

int KDE::backlight() {
	return getInt("getBrightness");
}

void KDE::backlight(int backlight) {
	exec("setBrightness", g_variant_new("(i)",backlight));
}

bool KDE::isWorking() {
	return backlight() != -1;
}

int KDE::weight() {
	return 3;
}

std::unique_ptr<Backend> KDE::create() {
	return std::unique_ptr<Backend>(new KDE());
}
