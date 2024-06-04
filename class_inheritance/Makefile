DEPDIR := .deps
$(shell mkdir -p $(DEPDIR) >/dev/null)

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$@.d
CXXFLAGS = -g -std=c++23 -pedantic -Wall -Wextra -Werror -Wshadow -Wconversion -Wunreachable-code

SRCS := diamond_problem_example.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
TARGETS = $(SRCS:.cpp=)

all: $(TARGETS) $(TEST_TARGET)

format: $(SRCS)
	clang-format --style=file $^ -i

%.o: %.cpp
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -c $< -o $@

%: %*.cpp
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -o $(notdir $@) $<

$(foreach s,$(SRCS),$(foreach o,$(filter %$(basename $s),$(TARGETS)),$(eval $o: $s)))
$(TARGETS):
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -o $@ $<

-include $(DEPDIR)/*.d

.PHONY: all clean
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(notdir $(TARGETS))
	rm -rf $(DEPDIR)
