CXX = g++ -std=c++11
LIBS = -lm
INCLUDE_DIRS = -I..

SOURCES = 1.cc 2.cc 3.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../*.hh
	$(CXX) $(LIBS) $(INCLUDE_DIRS) $< -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
