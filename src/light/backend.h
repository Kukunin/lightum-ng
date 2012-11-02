#ifndef LIGHT_BACKEND_H
#define LIGHT_BACKEND_H

namespace Light {

	class Backend {
		public:
			virtual ~Backend() {};
			/**
			 * @returns: light value between 0 and 100
			 */
			virtual int light() = 0;
			/**
			 * @returns: whether backend is working on this system or not
			 */
			virtual bool isWorking() = 0;
			/**
			 * @returns: weight of backend. Used when optimal backend is choosing
			 */
			virtual int weight() = 0;

			static Backend* create();
	};

	typedef Backend* (*CreateBackend)();
}

#endif
