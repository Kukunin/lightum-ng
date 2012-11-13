#ifndef MAIN_H
#define MAIN_H

#include "config.h"
#include "screen/backend.h"
#include "light/backend.h"
#include "kbd/backend.h"
#include "backendmanager.h"

#include <memory>
#include <exception>

namespace Core {

	enum WorkingMode {
		ScreenMode    = 1,
		KeyboardMode  = 2
	};

	class Main {
		public:
			Main( std::shared_ptr<Config> config );
			~Main();
			void loop();

		private:
			std::shared_ptr<Config> config;
			BackendManager backendManager;

			std::unique_ptr<Screen::Backend> screenBackend;
			std::unique_ptr<Light::Backend> lightBackend;
			std::unique_ptr<Keyboard::Backend> kbdBackend;

			int mode;

	};
}

#endif
