CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall -lpthread

build_all: all

include math/makefile
include threads/makefile

ALL_OBJECTS = $(MATH_OBJECTS) $(THREADS_OBJECTS)

all: math threads
	$(CC) main.cpp $(LFLAGS) $(ALL_OBJECTS) -o tekstorm

clean:
	rm ./bin/*.o
