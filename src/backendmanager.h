#ifndef CORE_BACKENDMANAGER_H
#define CORE_BACKENDMANAGER_H

#include "screen/backend.h"
#include "light/backend.h"
#include "kbd/backend.h"

#include <map>
#include <string>

namespace Core {

	typedef std::map<std::string,Keyboard::CreateBackend> kbdMap;
	typedef std::map<std::string,Screen::CreateBackend> screenMap;
	typedef std::map<std::string,Light::CreateBackend> lightMap;

	/**
	 * Checks all available backends
	 * Chooses the most optimal backend
	 * Return the pointer to the backend
	 * ToDo Use dynamic loaded backends
	 * ToDo Use templates and one method 'getBackend'
	 */
	class BackendManager {
		public:
			static BackendManager* getInstance();
			Screen::Backend *getScreenBackend();
			Light::Backend *getLightBackend();
			Keyboard::Backend *getKbdBackend();

		private:
			BackendManager();
			~BackendManager();

			kbdMap kbdBackends;
			screenMap screenBackends;
			lightMap lightBackends;

			static BackendManager* inst;

	};
}

#endif
