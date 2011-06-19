MATH_SOURCES = math/Vector2.cpp math/Vector3.cpp math/Vector4.cpp math/Color3.cpp math/Color4.cpp
MATH_OBJECTS = bin/Vector2.o bin/Vector3.o bin/Vector4.o bin/Color3.o bin/Color4.o

# make math
math: $(MATH_OBJECTS)

Vector2.o: math/Vector2.cpp math/Vector2.h
	$(CC) $(CFLAGS) math/Vector2.cpp  -o bin/Vector2.o

Vector3.o: math/Vector3.cpp math/Vector3.h
	$(CC) $(CFLAGS) math/Vector3.cpp -o bin/Vector3.o

Vector4.o: math/Vector4.cpp math/Vector4.h
	$(CC) $(CFLAGS) math/Vector4.cpp  -o bin/Vector4.o

Color3.o: math/Color3.cpp math/Color3.h
	$(CC) $(CFLAGS) math/Color3.cpp  -o bin/Color3.o

Color4.o: math/Color4.cpp math/Color4.h
	$(CC) $(CFLAGS) math/Color4.cpp -o bin/Color4.o
