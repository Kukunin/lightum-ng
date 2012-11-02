#include "dbus.h"
#include "config.h"

#include <cstdio>
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
	if ( !typeInited ) {
		g_type_init();
		typeInited = true;
	}

	conn = g_bus_get_sync(type, NULL, &error);
	if ( g_dbus_connection_is_closed(conn) ) {
		printError();
	}

	this->busName = busName;
	this->objectPath = objectPath;
	this->interface = interface;

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

GVariant* DBus::query( const gchar *method_name, GVariant *parameters) {

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
	if ( Core::Config::getInstance()->verbose() ) {
		fprintf(stderr, "%s\n", error->message);
	}
}
