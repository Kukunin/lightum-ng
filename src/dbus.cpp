#include "dbus.h"
#include "config.h"

#include <iostream>

using namespace Core;

bool DBus::typeInited = false;

DBus::DBus() {
	DBus(G_BUS_TYPE_SESSION);
}
DBus::DBus( GBusType type ) {
	DBus(type,"","","");
}
DBus::DBus( GBusType type, const char * busName, const char * objectPath, const char * interface ) {
	//Depreciated in glib 2.36
	if ( !typeInited ) {
		g_type_init();
		typeInited = true;
	}

	this->busName = busName;
	this->objectPath = objectPath;
	this->interface = interface;

	//ToDo make DBus connection global. Init and Close in one place
	//Init private DBus connection
	error = NULL;
	gchar* address = g_dbus_address_get_for_bus_sync (type, NULL, &error);

	if (address == NULL) {
		printError();
	} else {
		error = NULL;
		conn = g_dbus_connection_new_for_address_sync (address,
				(GDBusConnectionFlags)(G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_CLIENT
					| G_DBUS_CONNECTION_FLAGS_MESSAGE_BUS_CONNECTION),
				NULL,
				NULL,
				&error);
		g_free (address);

		if ( conn == NULL || g_dbus_connection_is_closed(conn) ) {
			printError();
		}
	}

}
DBus::~DBus() {
	if ( !g_dbus_connection_is_closed(conn) ) {
		error = NULL;
		if (!g_dbus_connection_close_sync(conn,NULL,&error) ) {
			printError();
		}
		g_object_unref(conn);
	}
	if ( error != NULL ) {
		g_error_free(error);
	}
}

GVariant* DBus::query( const gchar *method_name, GVariant *parameters) {

	error = NULL;
	GVariant *res = g_dbus_connection_call_sync(
			conn,
			busName,
			objectPath,
			interface,
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

void DBus::exec( const gchar *method_name, GVariant *parameters) {
	GVariant *res = query(method_name, parameters);

	if ( res != NULL ) {
		g_variant_unref( res );
	}
}

int DBus::getInt(const gchar *method_name) {
	GVariant *res = query(method_name, NULL );

	if ( res == NULL ) {
		return -1;
	}

	int value;
	g_variant_get(res, "(i)", &value);
	g_variant_unref( res );

	return value;
}

void DBus::printError() {
	if ( error != NULL ) {
		if (Core::Config::getInstance()->verbose()) {
			std::cerr << error->message << std::endl;
		}
		g_error_free(error);
		error = NULL;
	}
}
