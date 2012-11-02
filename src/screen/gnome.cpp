#include "gnome.h"

using namespace Screen;

Gnome::Gnome()
	: DBus(G_BUS_TYPE_SESSION, "org.gnome.SettingsDaemon", "/org/gnome/SettingsDaemon/Power", "org.gnome.SettingsDaemon.Power.Screen")
{

}

Gnome::~Gnome() {

}

int Gnome::backlight() {
	GVariant *res = query("GetPercentage", NULL);

	if ( res == NULL ) {
		return -1;
	}

	int backlight;
	g_variant_get(res, "(i)", &backlight);
	g_variant_unref( res );

	return backlight;
}

void Gnome::backlight(int backlight) {
	GVariant *res = query("SetPercentage", g_variant_new("(i)",backlight));

	if ( res != NULL ) {
		g_variant_unref( res );
	}
}

bool Gnome::isWorking() {
	return backlight() != -1;
}

int Gnome::weight() {
	return 3;
}

