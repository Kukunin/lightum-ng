#include "backendmanager.h"

#include "kbd/upower.h"
#include "screen/xbacklight.h"
#include "screen/gnome.h"
#include "screen/kde.h"
#include "light/apple.h"

using namespace Core;

BackendManager::BackendManager() {
	kbdBackends["UPower"] = &Keyboard::UPower::create;

	screenBackends["XBacklight"] = &Screen::XBacklight::create;
	screenBackends["Gnome"] = &Screen::Gnome::create;
	screenBackends["KDE"] = &Screen::KDE::create;

	lightBackends["Apple"] = &Light::Apple::create;
}

BackendManager::~BackendManager() {

}

std::unique_ptr<Screen::Backend> BackendManager::getScreenBackend() {

	std::unique_ptr<Screen::Backend> ret;
	int weight = 0;

	for ( auto it = begin(screenBackends); it != end(screenBackends); it++ ) {
		auto tmp = (*it).second();
		if ( tmp->isWorking() ) {
			if ( tmp->weight() > weight ) {
				//Assign new better backend
				weight = tmp->weight();
				ret = std::move(tmp);
			}
		}
	}
	return ret;
}

std::unique_ptr<Light::Backend> BackendManager::getLightBackend() {

	std::unique_ptr<Light::Backend> ret;
	int weight = 0;

	for ( auto it = begin(lightBackends); it != end(lightBackends); it++ ) {
		auto tmp = (*it).second();
		if ( tmp->isWorking() ) {
			if ( tmp->weight() > weight ) {
				//Assign new better backend
				weight = tmp->weight();
				ret = std::move(tmp);
			}
		}
	}
	return ret;
}

std::unique_ptr<Keyboard::Backend> BackendManager::getKbdBackend() {

	std::unique_ptr<Keyboard::Backend> ret;
	int weight = 0;

	for ( auto it = begin(kbdBackends); it != end(kbdBackends); it++ ) {
		auto tmp = (*it).second();
		if ( tmp->isWorking() ) {
			if ( tmp->weight() > weight ) {
				//Assign new better backend
				weight = tmp->weight();
				ret = std::move(tmp);
			}
		}
	}
	return ret;
}
