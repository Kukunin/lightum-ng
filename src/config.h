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
			int delay();
			int minScreenBacklight();
			int minKeyboardBacklight();

		private:
			bool _verbose;
			int _delay;
			int _minScreenBacklight;
			int _minKbdBacklight;

	};

}

#endif
