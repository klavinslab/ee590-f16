#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  matrix<double> A(3,3);

  try {
     matrix<double> D(3,4), E(4,5);
     A = D.add(E);
     FAIL;
  } catch ( matrix_exception &e ) {
    SUCCEED;
  }

}
