CXX = clang++
CXXFLAGS = -std=c++14 -pedantic -Wextra -Wall -Weffc++

all: operators
.PHONY: all clean

% : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm operators
