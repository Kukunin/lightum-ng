#ifndef CONFIG_H
#define CONFIG_H

namespace Core {

	/**
	 * Singletone for the Config
	 */
	class Config {
		public:
			static Config* getInstance();
			bool verbose();

		private:
			bool _verbose;

			Config();
			~Config();
			static Config *instance;
	};

}

#endif
