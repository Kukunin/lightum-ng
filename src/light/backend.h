#ifndef LIGHT_BACKEND_H
#define LIGHT_BACKEND_H

#include "../backend.h"

#include <memory>

namespace Light {

	class Backend : public Core::Backend {
		public:
			/**
			 * @returns: light value between 0 and 100
			 */
			virtual int light() = 0;
	};
}

#endif
