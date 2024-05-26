
CXX = clang++
CXXFLAGS = -std=c++14 -pedantic -Wextra -Wall -Weffc++

all: rule_of_three
.PHONY: all clean

% : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	-rm rule_of_three

rule_of_three: rule_of_three.cpp
:q
