#ifndef CORE_BACKENDMANAGER_H
#define CORE_BACKENDMANAGER_H

#include "screen/backend.h"
#include "light/backend.h"
#include "kbd/backend.h"

#include <map>
#include <memory>
#include <string>

namespace Core {

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

			std::map<std::string,Keyboard::CreateBackend> kbdBackends;
			std::map<std::string,Screen::CreateBackend> screenBackends;
			std::map<std::string,Light::CreateBackend> lightBackends;

	};
}

#endif
