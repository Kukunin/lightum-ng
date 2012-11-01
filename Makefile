DESTDIR?=/
SHELL = /bin/sh
CXX?=g++
CXXFLAGS = -Wall -Wextra -Wwrite-strings -O -g
LDFLAGS=
INSTALL = /usr/bin/install -c
INSTALLDATA = /usr/bin/install -c -m 644

srcdir = .
prefix = $(DESTDIR)
bindir = $(prefix)/usr/bin
docdir = $(prefix)/usr/share/doc
mandir = $(prefix)/usr/share/man

OBJ=src/main.o src/screen/xbacklight.o
BIN=lightum

all: ${OBJ}
	$(CXX) $(CXXFLAGS) ${OBJ} $(LDFLAGS) -o ${BIN}

install: all
	echo "I guess, you don't want to install THIS onto your system yet."

uninstall:

clean:
	rm -f $(BIN)
	find . -name \*.o -delete
