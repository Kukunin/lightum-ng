#ifndef CORE_BACKEND_H
#define CORE_BACKEND_H

#include <memory>

namespace Core {

	class Backend {

		public:
			virtual ~Backend() {};
			/**
			 * @returns: whether backend is working on this system or not
			 */
			virtual bool isWorking() = 0;
			/**
			 * @returns: weight of backend. Used when optimal backend is choosing
			 */
			virtual int weight() = 0;

			static std::unique_ptr<Backend> create();
	};

	typedef std::unique_ptr<Backend> (*CreateBackend)();
}

#endif
