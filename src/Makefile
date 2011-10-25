VERSION=0.0.1

CC=gcc
CFLAGS=-Wall -Wno-pointer-sign -g
INSTALL=install

# these locations seem to work for SuSE, Fedora, and Debian
prefix = $(DESTDIR)/usr
BINDIR = $(prefix)/bin
DATADIR = $(prefix)/share
DESKTOPDIR = $(DATADIR)/applications
ICONPATH = $(DATADIR)/icons/hicolor
ICONDIR = $(ICONPATH)/scalable/apps
MANDIR = $(DATADIR)/man/man1
gtk_update_icon_cache = gtk-update-icon-cache -f -t $(ICONPATH)

NAME = schlaser
ICONFILE = images/beer.png
DESKTOPFILE = $(NAME).desktop
MANFILES = $(NAME).1

LIBGTK = $(shell pkg-config --libs gtk+-2.0 glib-2.0 gconf-2.0)

LIBS = $(LIBGTK) -lpthread

OBJS = 	main.o gtk-gui.o

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME).exe $(OBJS) $(LIBS)

install: $(NAME)
	$(INSTALL) -d -m 755 $(BINDIR)
	$(INSTALL) $(NAME) $(BINDIR)
	$(INSTALL) -d -m 755 $(DESKTOPDIR)
	$(INSTALL) $(DESKTOPFILE) $(DESKTOPDIR)
	$(INSTALL) -d -m 755 $(ICONDIR)
	$(INSTALL) $(ICONFILE) $(ICONDIR)
	$(gtk_update_icon_cache)
	$(INSTALL) -d -m 644 $(MANDIR)
	$(INSTALL) $(MANFILES) $(MANDIR)

main.o: main.c schlaser.h
	$(CC) $(CFLAGS) `pkg-config --cflags glib-2.0` \
		-c main.c

gtk-gui.o: gtk-gui.c schlaser.h Makefile
	$(CC) $(CFLAGS) `pkg-config --cflags gtk+-2.0 glib-2.0 gconf-2.0` \
			-DVERSION_STRING='"v$(VERSION)"' \
			-c gtk-gui.c

clean:
	rm -f $(OBJS) *~ $(NAME).exe
