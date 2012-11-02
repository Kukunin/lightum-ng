DESTDIR?=/
SHELL = /bin/sh
CXX?=g++
CXXFLAGS = `pkg-config --cflags gio-2.0` -Wall -Wextra -Wwrite-strings -O -g
LDFLAGS= `pkg-config --libs gio-2.0`
INSTALL = /usr/bin/install -c
INSTALLDATA = /usr/bin/install -c -m 644

srcdir = .
prefix = $(DESTDIR)
bindir = $(prefix)/usr/bin
docdir = $(prefix)/usr/share/doc
mandir = $(prefix)/usr/share/man

OBJ=	src/main.o \
		src/dbus.o \
		src/config.o \
		src/screen/xbacklight.o \
		src/screen/gnome.o \
		src/screen/kde.o \
		src/light/apple.o \
		src/kbd/upower.o

BIN=lightum

all: ${OBJ}
	$(CXX) $(CXXFLAGS) ${OBJ} $(LDFLAGS) -o ${BIN}

install: all
	echo "I guess, you don't want to install THIS onto your system yet."

uninstall:

clean:
	rm -f $(BIN)
	find . -name \*.o -delete
