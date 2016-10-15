CXX = g++ -std=c++11 -O3

SOURCES = matrix.cc matrix_operations.cc
HEADERS = matrix.hh

OBJECTS=$(SOURCES:.cc=.o)

LIB_MATRIX=libmatrix.a

all: $(LIB_MATRIX)
	make -C test

$(LIB_MATRIX): $(OBJECTS) $(HEADERS)
	ar cr $(LIB_MATRIX) $(OBJECTS)

%.o: %.c $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f $(OBJECTS) $(LIB_MATRIX)
	make -C test clean
