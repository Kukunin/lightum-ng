#include "dbus.h"

#include <cstdio>

using namespace Core;

bool DBus::typeInited = false;

DBus::DBus() {
	DBus(G_BUS_TYPE_SESSION);
}
DBus::DBus( GBusType type ) {
	if ( !typeInited ) {
		g_type_init();
		typeInited = true;
	}

	conn = g_bus_get_sync(type, NULL, &error);
	if ( g_dbus_connection_is_closed(conn) ) {
		printError();
	}
}
DBus::~DBus() {
	if ( !g_dbus_connection_is_closed(conn) ) {
		if (!g_dbus_connection_close_sync(conn,NULL,&error) ) {
			printError();
		}
	}
	if ( error != NULL ) {
		g_error_free(error);
	}
}

GVariant* DBus::query(
	const gchar *bus_name,
	const gchar *object_path,
	const gchar *interface_name,
	const gchar *method_name,
	GVariant *parameters)
{
	GVariant *res = g_dbus_connection_call_sync(
			conn,
			bus_name,
			object_path,
			interface_name,
			method_name,
			parameters,
			NULL,
			G_DBUS_CALL_FLAGS_NONE,
			-1,
			NULL,
			&error);

	if ( res == NULL ) {
		printError();
		return NULL;
	}

	return res;
}

void DBus::printError() {
	fprintf(stderr, "%s\n", error->message);
}
