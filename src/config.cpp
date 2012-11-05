#include "config.h"

using namespace Core;

Config::Config() {
	_verbose = true;

}
Config::~Config() {
}

bool Config::verbose() {
	return _verbose;
}
