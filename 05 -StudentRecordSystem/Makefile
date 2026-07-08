CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g
TARGET = student_record_system

SRCS = main.cpp Student.cpp LinkedList.cpp Searching.cpp Sorting.cpp Statistics.cpp Utility.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) students.dat

run: all
	./$(TARGET)

.PHONY: all clean run
