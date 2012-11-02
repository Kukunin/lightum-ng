#include "config.h"

using namespace Core;

Config* Config::instance = 0;

Config* Config::getInstance() {
	if ( instance == 0 ) {
		instance = new Config();
	}
	return instance;
}

Config::Config() {
	_verbose = true;

}
Config::~Config() {
	delete instance;
}

bool Config::verbose() {
	return _verbose;
}
