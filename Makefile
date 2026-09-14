CXX = clang++
CXXFLAGS = -std=c++17 -Wall $(shell pkg-config --cflags raylib)
LDFLAGS = $(shell pkg-config --libs raylib)

SRCS = main.cpp renderer.cpp camera.cpp object.cpp engine.cpp
TARGET = gravity_well

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
