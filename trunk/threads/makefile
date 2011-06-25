THREADS_SOURCES = threads/Mutex.cpp threads/Thread.cpp
THREADS_OBJECTS = bin/Mutex.o bin/Thread.o
THREADS_DEPS = Mutex Thread

# make math
threads: $(THREADS_DEPS)

Mutex: threads/Mutex.cpp threads/Mutex.h
	$(CC) $(CFLAGS) threads/Mutex.cpp -o bin/Mutex.o

Thread: threads/Thread.cpp threads/Thread.h
	$(CC) $(CFLAGS) threads/Thread.cpp -o bin/Thread.o
