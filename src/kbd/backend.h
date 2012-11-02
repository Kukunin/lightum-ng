#ifndef KBD_BACKEND_H
#define KBD_BACKEND_H

#include "../backend.h"

#include <memory>

namespace Keyboard {

	class Backend : public Core::Backend{
		public:
			/**
			 * @returns: screen backlight value between 0 and 100
			 */
			virtual int backlight() = 0;
			/**
			 * @param: backlight value between 0 and 100
			 */
			virtual void backlight(int backlight) = 0;
	};
}

#endif
