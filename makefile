# edit this makefile so that running make compiles your enigma program
OBJS = Main.o Rotor.o Reflector.o Plugboard.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -Werror -pedantic -std=c++11 $(DEBUG)
LFLAGS = -Wall -Werror -pedantic -std=c++11 $(DEBUG)

enigma: $(OBJS)
	$(CC) $(CFLAGS) $^ -o enigma

Main.o: Main.cpp
	$(CC) $(CFLAGS) -c $^

Reflector.o: Reflector.cpp
	$(CC) $(CFLAGS) -c $^

Rotor.o: Rotor.cpp
	$(CC) $(CFLAGS) -c $^

Plugboard: Plugboard.cpp
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf enigma *.o

.PHONY: clean
