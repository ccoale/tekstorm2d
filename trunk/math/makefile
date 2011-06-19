MATH_SOURCES = math/Vector2.cpp math/Vector3.cpp math/Vector4.cpp math/Color3.cpp math/Color4.cpp
MATH_OBJECTS = bin/Vector2.o bin/Vector3.o bin/Vector4.o bin/Color3.o bin/Color4.o
MATH_DEPS = Vector2 Vector3 Vector4 Color3 Color4

# make math
math: $(MATH_DEPS)

Vector2: math/Vector2.cpp math/Vector2.h
	$(CC) $(CFLAGS) math/Vector2.cpp  -o bin/Vector2.o

Vector3: math/Vector3.cpp math/Vector3.h
	$(CC) $(CFLAGS) math/Vector3.cpp -o bin/Vector3.o

Vector4: math/Vector4.cpp math/Vector4.h
	$(CC) $(CFLAGS) math/Vector4.cpp  -o bin/Vector4.o

Color3: math/Color3.cpp math/Color3.h
	$(CC) $(CFLAGS) math/Color3.cpp  -o bin/Color3.o

Color4: math/Color4.cpp math/Color4.h
	$(CC) $(CFLAGS) math/Color4.cpp -o bin/Color4.o
