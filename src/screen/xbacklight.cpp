#include <cstdio>
#include <cstdlib>
#include <string>

#include "xbacklight.h"

using namespace Screen;

const char * XBacklight::CMD = "xbacklight";

XBacklight::~XBacklight() {

}
/**
ToDo rewrite on XCB util
See xbacklight sources
**/
int XBacklight::backlight() {

	auto deleter = [](FILE * f) { pclose(f); };
	std::unique_ptr<FILE, decltype(deleter)> f(
		popen( CMD, "r" ), deleter
	);

	if ( f.get() == 0 ) {
		throw std::string("Can't open xbacklight");
	}
	const int BUFSIZE = 1000;
	char buf[ BUFSIZE ];
	while( fgets( buf, BUFSIZE,  f.get() ) ) {
		;
	}
	return atoi(buf);
}
void XBacklight::backlight(int backlight) {
	char name[50];
	sprintf(name,"%s -set %d", CMD, backlight);
	system(name);
}
bool XBacklight::isWorking() {
	char name[50];
	sprintf(name,"%s > /dev/null 2>&1", CMD);
	return system(name) == 0;
}
int XBacklight::weight() {
	return 1;
}

std::unique_ptr<Core::Backend> XBacklight::create() {
	return std::unique_ptr<Core::Backend>(new XBacklight());
}
