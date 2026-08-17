CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Werror -g


TARGET = wayfarer

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)
	
clean:
	rm -f $(OBJS) $(TARGET)