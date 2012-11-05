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

	//Smart PTR on GError
	error = std::unique_ptr<GError*,std::function<void (GError **)>>(NULL, [](GError **e) {
		if ( e != NULL || *e != NULL ) {
			g_error_free(*e);
		}
	});

	auto gfree = [](gchar * p) { g_free(p); };
	std::unique_ptr<gchar, decltype(gfree)> address(
			g_dbus_address_get_for_bus_sync (type, NULL, error.get()), gfree
	);

	if (!address) {
		throwError();
	} else {
		GDBusConnection *connection = g_dbus_connection_new_for_address_sync (address.get(),
				(GDBusConnectionFlags)(G_DBUS_CONNECTION_FLAGS_AUTHENTICATION_CLIENT
					| G_DBUS_CONNECTION_FLAGS_MESSAGE_BUS_CONNECTION),
				NULL,
				NULL,
				error.get());

		//Deleter function for connection
		conn = std::unique_ptr<GDBusConnection,std::function<void (GDBusConnection *)>>(connection, [](GDBusConnection * c) {
			if ( !g_dbus_connection_is_closed(c) ) {
				g_dbus_connection_close_sync(c,NULL,NULL);
			}
			g_object_unref(c);
		});

		if ( !conn || g_dbus_connection_is_closed(conn.get()) ) {
			throwError();
		}
	}

}
DBus::~DBus() {

}

GVariant* DBus::query( const gchar *method_name, GVariant *parameters) {

	GVariant *res = g_dbus_connection_call_sync(
			conn.get(),
			busName,
			objectPath,
			interface,
			method_name,
			parameters,
			NULL,
			G_DBUS_CALL_FLAGS_NONE,
			-1,
			NULL,
			error.get());

	if ( res == NULL ) {
		throwError();
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

void DBus::throwError() {
	if ( error ) {
		if ( *(error.get()) != NULL ) {
			throw std::string((*(error.get()))->message);
		}
	}
}
