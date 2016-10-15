#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  // COUT TEST WITH INVERSE
  // This test checks that the << works with cout and matrices. It should print
  // out two matrices, and not crash.

  matrix M = matrix::random(6,6,-2,2);

  std::cout << std::endl;
  std::cout << "A random matrix ..." << std::endl;
  std::cout << M << std::endl;

  std::cout << "... and its inverse" << std::endl;
  std::cout << M.inverse() << std::endl;

  SUCCEED;

}
