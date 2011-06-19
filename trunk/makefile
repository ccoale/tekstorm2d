CC = g++
CFLAGS = -Wall -c
LFLAGS = -Wall

include math/makefile

ALL_OBJECTS = $(MATH_OBJECTS)

all: math
	$(CC) main.cpp $(LFLAGS) $(ALL_OBJECTS) -o tekstorm

clean:
	rm *.o
