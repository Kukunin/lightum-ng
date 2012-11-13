#include "config.h"

using namespace Core;

Config::Config() {
	_verbose = true;
	_delay = 1000;

}
Config::~Config() {
}

bool Config::verbose() {
	return _verbose;
}

int Config::delay() {
	return _delay;
}

void Config::parseArguments( int argc, char **argv ) {

}
