#ifndef SCREEN_KDE_H
#define SCREEN_KDE_H

#include "backend.h"
#include "../dbus.h"

#include <gio/gio.h>

namespace Screen {

	class KDE : public Backend, public Core::DBus {
		public:
			KDE();
			virtual ~KDE();
			int backlight();
			void backlight(int backlight);
			bool isWorking();
			int weight();
	};
}

#endif
