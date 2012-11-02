#include "gnome.h"

using namespace Screen;

Gnome::Gnome()
	: DBus(G_BUS_TYPE_SESSION, "org.gnome.SettingsDaemon", "/org/gnome/SettingsDaemon/Power", "org.gnome.SettingsDaemon.Power.Screen")
{

}

Gnome::~Gnome() {

}

int Gnome::backlight() {
	return getInt("GetPercentage");
}

void Gnome::backlight(int backlight) {
	exec("SetPercentage", g_variant_new("(i)",backlight));
}

bool Gnome::isWorking() {
	return backlight() != -1;
}

int Gnome::weight() {
	return 3;
}

std::unique_ptr<Backend> Gnome::create() {
	return std::unique_ptr<Backend>(new Gnome());
}
