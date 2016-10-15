#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  // CONSTRUCTOR TESTS
  // This file tests all constructors by building a matrix with each and then
  // testing that the matrix is the right size and/or that values in the matrix,
  // using get, are what they should be.

  // TEST 1: Check that a 2x2 matrix has two rows and two columns.
  matrix A(2,2);
  ASSERT ( A.rows() == 2 && A.columns() == 2 );

  // TEST 2: Check that a 3x3 random matrix has entries between -2 and 2
  // (inclusive).
  matrix R = matrix::random(3,3,-2,2);
  for ( int i=0; i<3; i++ ) {
    for ( int j=0; j<3; j++ ) {
      ASSERT ( -2 <= R.get(i,j) && R.get(i,j) <= 2 );
    }
  }

  // TEST 3: Check that a 4x4 identity matrix has 1s on the diagonal and 0s
  // elsewhere.
  matrix I = matrix::identity(4);
  for ( int i=0; i<4; i++ ) {
    for ( int j=0; j<4; j++ ) {
      ASSERT ( ( i == j && I.get(i,j) == 1 ) || ( i!=j && I.get(i,j) == 0 ) );
    }
  }

  // TEST 4: Check that a matrix of ones is a matrix of ones.
  matrix O = matrix::ones(5,6);
  for ( int i=0; i<5; i++ ) {
    for ( int j=0; j<5; j++ ) {
      ASSERT ( O.get(i,j) == 1 );
    }
  }

  SUCCEED;

}
