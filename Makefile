CXX = clang++
CXXFLAGS = -std=c++17 -Wall $(shell pkg-config --cflags raylib)
LDFLAGS = $(shell pkg-config --libs raylib)

SRCS = src/main.cpp src/renderer.cpp src/camera.cpp src/object.cpp src/engine.cpp src/initial_conditions.cpp src/orbit_trail.cpp src/spacetime.cpp
TARGET = gravity_well

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)
