CC = gcc
CFLAGS = -fPIC -pedantic -Wall -Wextra -O2 -Iinclude/
LIBFLAGS = -shared -lpthread

LIBNAME = liblogging.so

PREFIX = /usr/local
LIBINSTALL = $(PREFIX)/lib
INCLUDEINSTALL = $(PREFIX)/include

SRCFILES = ./src/log.c
OFILES = ./src/log.o
HEADERFILES = ./include/logging/log.h

.PHONY: all clean install uninstall

all: $(LIBNAME)

$(LIBNAME): $(OFILES)
	$(CC) $(LIBFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

install: $(LIBNAME)
	mkdir -p $(INCLUDEINSTALL)/logging
	cp -f $(HEADERFILES) $(INCLUDEINSTALL)/logging/
	cp -f $(LIBNAME) $(LIBINSTALL)
	chmod 755 $(LIBINSTALL)/$(LIBNAME)
	ldconfig

uninstall:
	rm -rf $(INCLUDEINSTALL)/logging
	rm -f $(LIBINSTALL)/$(LIBNAME)

clean:
	rm -f $(LIBNAME) $(OFILES)

