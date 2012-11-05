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
			bool verbose();

		private:
			bool _verbose;

	};

}

#endif
