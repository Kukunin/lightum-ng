#include "kde.h"

using namespace Screen;

const char * KDE::busName = "org.kde.Solid.PowerManagement";
const char * KDE::objectPath = "/org/kde/Solid/PowerManagement";
const char * KDE::interface = "org.kde.Solid.PowerManagement";

KDE::KDE()
	: DBus(G_BUS_TYPE_SESSION)
{

}

KDE::~KDE() {

}

int KDE::backlight() {
	GVariant *res = query(
			busName,
			objectPath,
			interface,
			"getBrightness",
			NULL);

	if ( res == NULL ) {
		return -1;
	}

	int backlight;
	g_variant_get(res, "(i)", &backlight);
	g_variant_unref( res );

	return backlight;
}

void KDE::backlight(int backlight) {
	GVariant *res = query(
			busName,
			objectPath,
			interface,
			"setBrightness",
			g_variant_new("(i)",backlight));

	if ( res != NULL ) {
		g_variant_unref( res );
	}
}

bool KDE::isWorking() {
	return backlight() != -1;
}

int KDE::weight() {
	return 3;
}

