#ifndef KBD_UPOWER_H
#define KBD_UPOWER_H

#include "backend.h"

namespace Keyboard {

	class UPower : public Backend {
		public:
			virtual ~UPower();
			int backlight();
			void backlight(int backlight);
			bool isWorking();
			int weight();
	};
}

#endif
