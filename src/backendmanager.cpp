#include "backendmanager.h"

#include "kbd/upower.h"
#include "screen/xbacklight.h"
#include "screen/gnome.h"
#include "screen/kde.h"
#include "light/apple.h"

using namespace Core;

BackendManager* BackendManager::inst = NULL;

BackendManager* BackendManager::getInstance() {
	if ( inst == NULL ) {
		inst = new BackendManager();
	}
	return inst;
}

BackendManager::BackendManager() {
	kbdBackends["UPower"] = &Keyboard::UPower::create;

	screenBackends["XBacklight"] = &Screen::XBacklight::create;
	screenBackends["Gnome"] = &Screen::Gnome::create;
	screenBackends["KDE"] = &Screen::KDE::create;

	lightBackends["Apple"] = &Light::Apple::create;
}

BackendManager::~BackendManager() {

}

Screen::Backend* BackendManager::getScreenBackend() {
	screenMap::iterator it;

	Screen::Backend* ret = NULL;
	int weight = 0;

	for ( it = screenBackends.begin(); it != screenBackends.end(); it++ ) {
		Screen::Backend* tmp = (*it).second();
		if ( tmp->isWorking() ) {
			if ( tmp->weight() > weight ) {
				//Assign new better backend
				weight = tmp->weight();
				if ( ret != NULL )
					delete ret;
				ret = tmp;
				continue;
			}
		}
		delete tmp;
	}
	return ret;
}

Light::Backend* BackendManager::getLightBackend() {
	lightMap::iterator it;

	Light::Backend* ret = NULL;
	int weight = 0;

	for ( it = lightBackends.begin(); it != lightBackends.end(); it++ ) {
		Light::Backend* tmp = (*it).second();
		if ( tmp->isWorking() ) {
			if ( tmp->weight() > weight ) {
				//Assign new better backend
				weight = tmp->weight();
				if ( ret != NULL )
					delete ret;
				ret = tmp;
				continue;
			}
		}
		delete tmp;
	}
	return ret;
}

Keyboard::Backend* BackendManager::getKbdBackend() {
	kbdMap::iterator it;

	Keyboard::Backend* ret = NULL;
	int weight = 0;

	for ( it = kbdBackends.begin(); it != kbdBackends.end(); it++ ) {
		Keyboard::Backend* tmp = (*it).second();
		if ( tmp->isWorking() ) {
			if ( tmp->weight() > weight ) {
				//Assign new better backend
				weight = tmp->weight();
				if ( ret != NULL )
					delete ret;
				ret = tmp;
				continue;
			}
		}
		delete tmp;
	}
	return ret;
}
