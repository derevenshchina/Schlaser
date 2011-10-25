VERSION=0.0.1

CC=gcc
CFLAGS=-Wall -Wno-pointer-sign -g

NAME = schlaser
ICONFILE = images/beer.png

LIBGTK = $(shell pkg-config --libs gtk+-2.0 glib-2.0 gconf-2.0)

LIBS = $(LIBGTK) -lpthread

OBJS = 	main.o gtk-gui.o

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME).exe $(OBJS) $(LIBS)

main.o: main.c schlaser.h
	$(CC) $(CFLAGS) `pkg-config --cflags glib-2.0` \
		-c main.c

gtk-gui.o: gtk-gui.c schlaser.h Makefile
	$(CC) $(CFLAGS) `pkg-config --cflags gtk+-2.0 glib-2.0 gconf-2.0` \
			-DVERSION_STRING='"v$(VERSION)"' \
			-c gtk-gui.c

clean:
	rm -f $(OBJS) *~ $(NAME).exe
