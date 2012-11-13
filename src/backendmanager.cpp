#include "backendmanager.h"

#include "kbd/upower.h"
#include "screen/xbacklight.h"
#include "screen/gnome.h"
#include "screen/kde.h"
#include "light/apple.h"

#include <stdexcept>

using namespace Core;

template <class T>
std::unique_ptr<T> getBackend(std::vector<Core::CreateBackend> backends) {

	std::unique_ptr<T> ret;
	int weight = 0;

	for ( auto it : backends ) {
		auto tmp = it();
		try {
			//Try to cast to needed class
			//We are safe to use static_cast, because
			//the list is hardcoded in the constructor
			std::unique_ptr<T> casted(static_cast<T*>(tmp.release()));
			if ( casted->isWorking() ) {
				if ( casted->weight() > weight ) {
					//Assign new better backend
					weight = casted->weight();
					ret = std::move(casted);
				}
			}
		} catch (const std::bad_cast& e) {
			continue;
		} catch (std::string str) {
;
		}
	}
	if ( !ret ) {
		throw std::runtime_error("No backend is available");
	}

	return ret;
}

BackendManager::BackendManager() {
	backends[KEYBOARD] = { &Keyboard::UPower::create };

	backends[SCREEN] = {
		&Screen::XBacklight::create,
		&Screen::Gnome::create,
		&Screen::KDE::create
	};

	backends[LIGHT] = { &Light::Apple::create };
}

BackendManager::~BackendManager() {

}

std::unique_ptr<Screen::Backend> BackendManager::getScreenBackend() {
	return getBackend<Screen::Backend>( backends[SCREEN] );
}

std::unique_ptr<Light::Backend> BackendManager::getLightBackend() {
	return getBackend<Light::Backend>( backends[LIGHT] );
}

std::unique_ptr<Keyboard::Backend> BackendManager::getKbdBackend() {
	return getBackend<Keyboard::Backend>( backends[KEYBOARD] );
}

