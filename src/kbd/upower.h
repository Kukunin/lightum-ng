#ifndef KBD_UPOWER_H
#define KBD_UPOWER_H

#include "backend.h"
#include "../dbus.h"

#include <gio/gio.h>

namespace Keyboard {

	class UPower : public Backend, public Core::DBus {
		public:
			UPower();
			virtual ~UPower();
			int backlight();
			void backlight(int backlight);
			bool isWorking();
			int weight();

		private:
			static const char * busName;
			static const char * objectPath;
			static const char * interface;
	};
}

#endif
