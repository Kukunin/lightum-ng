#include "config.h"

using namespace Core;

Config::Config() {
	_verbose = true;
	_delay = 1000;
	_minScreenBacklight = 10;
	_minKbdBacklight = 10;

}
Config::~Config() {
}

bool Config::verbose() {
	return _verbose;
}

int Config::delay() {
	return _delay;
}

int Config::minScreenBacklight() {
	return _minScreenBacklight;
}

int Config::minKeyboardBacklight() {
	return _minKbdBacklight;
}

void Config::parseArguments( int argc, char **argv ) {

}
