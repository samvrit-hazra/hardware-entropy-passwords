CC = gcc

CFLAGS = -Wall -Wextra -Werror -Iinclude -mrdrnd

SRC = src/main.c src/generator.c src/entropy.c src/args.c

TARGET = build/passgen

PREFIX ?= /usr/local

.PHONY: all run install uninstall clean

all: $(TARGET)

$(TARGET):
	mkdir -p build
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: all
	./$(TARGET)

install: all
	mkdir -p $(PREFIX)/bin
	cp $(TARGET) $(PREFIX)/bin/passgen

uninstall:
	rm -f $(PREFIX)/bin/passgen

clean:
	rm -rf build
