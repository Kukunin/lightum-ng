#include <cstdio>
#include <cstdlib>

#include "xbacklight.h"

using namespace Screen;

const char * XBacklight::cmd = "xbacklight";

/** ToDo rewrite on XCB util **/
int XBacklight::backlight() {
	FILE * f = popen( cmd, "r" );
	if ( f == 0 ) {
		fprintf( stderr, "Could not execute\n" );
		return -1;
	}
	const int BUFSIZE = 1000;
	char buf[ BUFSIZE ];
	while( fgets( buf, BUFSIZE,  f ) ) {
		;
	}
	pclose( f );
	return atoi(buf);
}
void XBacklight::backlight(int backlight) {
	char name[50];
	sprintf(name,"%s -set %d", cmd, backlight);
	system(name);
}
bool XBacklight::isWorking() {
	char name[50];
	sprintf(name,"%s > /dev/null 2>&1", this->cmd);
	return system(name) == 0;
}
int XBacklight::weight() {
	return 10;
}
