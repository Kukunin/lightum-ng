#include "apple.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace Light;

const char * Apple::PATH = "/sys/devices/platform/applesmc.768/light";
const int Apple::MAXLV = 255;

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

/* Convert value with exponential function */
int Apple::convertTo(int light) {
	return std::log(light+1)/std::log(MAXLV+1) * 100;
}

int Apple::parse(std::string value) {
	return atoi(value.substr(1, value.find_first_of(',') - 1).c_str());
}

std::unique_ptr<Core::Backend> Apple::create() {
	return std::unique_ptr<Core::Backend>(new Apple());
}
