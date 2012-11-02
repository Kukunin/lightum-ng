#include "backendmanager.h"

#include "kbd/upower.h"
#include "screen/xbacklight.h"
#include "screen/gnome.h"
#include "screen/kde.h"
#include "light/apple.h"

using namespace Core;

BackendManager::BackendManager() {
	//Keyboard backends
	backends["UPower"] = &Keyboard::UPower::create;

	//Screen backends
	backends["XBacklight"] = &Screen::XBacklight::create;
	backends["Gnome"] = &Screen::Gnome::create;
	backends["KDE"] = &Screen::KDE::create;

	//Light sensor backends
	backends["Apple"] = &Light::Apple::create;
}

BackendManager::~BackendManager() {

}

std::unique_ptr<Backend> BackendManager::getBackend() {

	std::unique_ptr<Backend> ret;
	int weight = 0;

	for ( auto it = begin(backends); it != end(backends); it++ ) {
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
