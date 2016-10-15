CXX = g++ -std=c++11 -O3
LIBS = -lm -lmatrix
INCLUDE_DIRS = -I..
LIBDIRS = -L..

SOURCES = 1.cc 2.cc 3.cc 4.cc
TARGETS = $(SOURCES:%.cc=%.x)

all: $(TARGETS)

%.x: %.cc ../libmatrix.a
	$(CXX) $(LIBS) $(INCLUDE_DIRS) $(LIBDIRS) $< -o $@

test: $(TARGETS)
	./test.sh

clean:
	rm -rf $(TARGETS)
