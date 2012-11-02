#ifndef KBD_BACKEND_H
#define KBD_BACKEND_H

#include <memory>

namespace Keyboard {

	class Backend {
		public:
			virtual ~Backend() {};
			/**
			 * @returns: screen backlight value between 0 and 100
			 */
			virtual int backlight() = 0;
			/**
			 * @param: backlight value between 0 and 100
			 */
			virtual void backlight(int backlight) = 0;
			/**
			 * @returns: whether backend is working on this system or not
			 */
			virtual bool isWorking() = 0;
			/**
			 * @returns: weight of backend. Used when optimal backend is choosing
			 */
			virtual int weight() = 0;

			static std::unique_ptr<Backend> create();
	};

	typedef std::unique_ptr<Backend> (*CreateBackend)();
}

#endif
