#ifndef SCREEN_XBACKLIGHT_H
#define SCREEN_XBACKLIGHT_H

#include "backend.h"

namespace Screen {

	class XBacklight : public Backend {
	public:
		int backlight();
		void backlight(int backlight);
		bool isWorking();
		int weight();

	private:
		static const char * cmd;
	};
}

#endif
