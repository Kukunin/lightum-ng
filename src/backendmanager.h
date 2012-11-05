#ifndef CORE_BACKENDMANAGER_H
#define CORE_BACKENDMANAGER_H

#include "screen/backend.h"
#include "light/backend.h"
#include "kbd/backend.h"

#include <map>
#include <vector>
#include <memory>
#include <string>

namespace Core {

	enum BackendType {
		SCREEN,
		LIGHT,
		KEYBOARD
	};

	/**
	 * Checks all available backends
	 * Chooses the most optimal backend
	 * Return the pointer to the backend
	 * ToDo Use dynamic loaded backends
	 * ToDo Use templates and one method 'getBackend'
	 */
	class BackendManager {
		public:
			BackendManager();
			~BackendManager();

			std::unique_ptr<Screen::Backend> getScreenBackend();
			std::unique_ptr<Light::Backend> getLightBackend();
			std::unique_ptr<Keyboard::Backend> getKbdBackend();

		private:

			std::map<BackendType, std::vector<Core::CreateBackend>> backends;
	};
}

#endif
