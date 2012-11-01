#ifndef DBUS_H
#define DBUS_H

#include <gio/gio.h>

namespace Core {

	class DBus {
		public:
			DBus();
			DBus( GBusType type );
			virtual ~DBus();

		protected:
			GVariant* query(
				const gchar *bus_name,
				const gchar *object_path,
				const gchar *interface_name,
				const gchar *method_name,
				GVariant *parameters);

			void printError();

			GDBusConnection *conn;
			GError *error;
			static bool typeInited;
	 };

}

#endif
