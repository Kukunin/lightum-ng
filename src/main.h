#ifndef MAIN_H
#define MAIN_H

#include "config.h"
#include "screen/backend.h"
#include "light/backend.h"
#include "kbd/backend.h"
#include "backendmanager.h"

#include <memory>

namespace Core {

	class Main {
		public:
			Main( std::shared_ptr<Config> config );
			~Main();
			void loop();

		private:
			std::shared_ptr<Config> config;
			BackendManager backendManager;

	};
}

#endif
