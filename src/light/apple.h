#ifndef LIGHT_APPLE_H
#define LIGHT_APPLE_H

#include "backend.h"

#include <string>

namespace Light {

	class Apple : public Backend {
		public:
			virtual ~Apple();
			int light();
			bool isWorking();
			int weight();

		protected:
			/**
			 * Converts internal light value to common
			 * @param: input light value
			 * @return: light value between 0 to 100
			 */
			int convertTo( int light );
			int parse( std::string value );
			static const char * PATH;
			static const int    MAXLV;
	};
}

#endif
