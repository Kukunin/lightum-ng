#ifndef CONFIG_H
#define CONFIG_H

namespace Core {

	/**
	 * Singletone for the Config
	 */
	class Config {
		public:
			Config();
			~Config();

			void parseArguments( int argc, char **argv );

			bool verbose();

		private:
			bool _verbose;

	};

}

#endif
