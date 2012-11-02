#ifndef SCREEN_GNOME_H
#define SCREEN_GNOME_H

#include "backend.h"
#include "../dbus.h"

#include <gio/gio.h>

namespace Screen {

	class Gnome : public Backend, public Core::DBus {
		public:
			Gnome();
			virtual ~Gnome();
			int backlight();
			void backlight(int backlight);
			bool isWorking();
			int weight();
			static std::unique_ptr<Core::Backend> create();
	};
}

#endif
