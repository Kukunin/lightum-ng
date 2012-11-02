#ifndef DBUS_H
#define DBUS_H

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

			void printError();

			GDBusConnection *conn;
			GError *error;
			static bool typeInited;

			const char * busName;
			const char * objectPath;
			const char * interface;
	 };

}

#endif
