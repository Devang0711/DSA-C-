CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET = memory_calculator

SRCS = main.cpp MemoryTracker.cpp StaticDemo.cpp DynamicDemo.cpp DynamicArrayOOP.cpp OOPMemoryDemo.cpp VectorDemo.cpp Utility.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

run: all
	./$(TARGET)

.PHONY: all clean run
