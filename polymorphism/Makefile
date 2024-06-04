DEPDIR := .deps
$(shell mkdir -p $(DEPDIR) >/dev/null)

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$@.d
CXXFLAGS = -g -std=c++23 -pedantic -Wall -Wextra -Werror -Wshadow -Wconversion -Wunreachable-code -Isrc

SRCS := polymorphism_derivations_and_diamond_problem.cpp
OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)
TARGETS = $(notdir $(SRCS:.cpp=))

all: $(TARGETS) $(TEST_TARGET)

format: $(SRCS)
	clang-format --style=file $^

test : ass02_tests
	./$<

%.o: %.cpp
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -c $< -o $@

%: %*.cpp
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -o $(notdir $@) $<

$(foreach s,$(SRCS),$(foreach o,$(filter %$(basename $(notdir $s)),$(TARGETS)),$(eval $o: $s)))
$(TARGETS):
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) -o $@ $<

-include $(DEPDIR)/*.d

.PHONY: all clean
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(notdir $(TARGETS))
	rm -rf $(DEPDIR)
