#include "apple.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace Light;

const char * Apple::PATH = "/sys/devices/platform/applesmc.768/light";
const int Apple::MAXLV = 15;

Apple::~Apple() {

}

int Apple::light() {

	std::ifstream sensor(PATH);
	if ( sensor.is_open() ) {
		std::stringstream result;
		result << sensor.rdbuf();

		sensor.close();
		return convertTo(parse(result.str()));
	} else {
		return -1;
	}
}

bool Apple::isWorking() {
	std::ifstream sensor(PATH);
	bool ret = sensor.good();
	sensor.close();
	return ret;
}

int Apple::weight() {
	return 10;
}

int Apple::convertTo(int light) {
	return light * 100 / MAXLV;
}

int Apple::parse(std::string value) {
	return atoi(value.substr(1, value.find_first_of(',') - 1).c_str());
}
