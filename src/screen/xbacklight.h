#ifndef SCREEN_XBACKLIGHT_H
#define SCREEN_XBACKLIGHT_H

#include "backend.h"

namespace Screen {

	class XBacklight : public Backend {
		public:
			virtual ~XBacklight();
			int backlight();
			void backlight(int backlight);
			bool isWorking();
			int weight();
			static std::unique_ptr<Backend> create();

		private:
			static const char * CMD;
	};
}

#endif
