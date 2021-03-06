#ifndef DBUS_H
#define DBUS_H

#include <memory>
#include <gio/gio.h>

namespace Core {

	class DBus {
		public:
			DBus();
			DBus( GBusType type );
			DBus( GBusType type, const char *, const char *, const char * );
			virtual ~DBus();

		protected:
			GVariant* query( const gchar *method_name, GVariant *parameters);
			/**
			 * Make API Call and convert result to int32
			 * @return -1 on error or result in int32 type
			 */
			int getInt(const gchar *method_name);
			/**
			 * Make API Call with arguments without any result
			 */
			void exec( const gchar *method_name, GVariant *parameters);

			std::unique_ptr<GDBusConnection,std::function<void (GDBusConnection *)>> conn;
			std::unique_ptr<GError*,std::function<void (GError **)>> error;
			static bool typeInited;

			void throwError();

			const char * busName;
			const char * objectPath;
			const char * interface;
	 };

}

#endif
