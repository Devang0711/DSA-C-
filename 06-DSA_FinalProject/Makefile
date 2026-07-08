CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET = dsa_final_project

SRCS = main.cpp LinkedList.cpp Sorting.cpp Searching.cpp Tree.cpp Graph.cpp Utility.cpp
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
