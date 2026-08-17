# Compiler settings
CXX = g++
# Strict C++11 flags to catch all warnings
CXXFLAGS = -std=c++11 -Wall -Wextra -Wpedantic -Werror -g

# Target executable name
TARGET = wayfarer

# Grab all .cpp files automatically
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Valgrind memory leak check
memcheck: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

# Clean
clean:
	rm -f $(OBJS) $(TARGET)