#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  // DETERMINANT, INVERSE TEST, and COMPARISON TEST
  // This test first finds an invertable 4x4 matrix by checking the determinant
  // and making a new matrix until it is not zero. Then it computes the inverse.
  // Finally, it checks that the matrix times its inverse is approximately
  // equal to the identity.

  SRAND; // seeds the random number generator. See test.hh

  matrix Q = matrix::random(4,4,-2,2);
  std::cout << Q << std::endl;
  std::cout << Q.det() << std::endl;

  while ( Q.det() == 0 ) {
    Q = matrix::random(4,4,-2,2);
    std::cout << Q << std::endl;
    std::cout << Q.det() << std::endl;
  }

  std::cout << "--" << std::endl;

  matrix M = Q * (Q.inverse()),
         eps = matrix::ones(4,4),
         I = matrix::identity(4);

  eps.scale ( 0.0001 );

  ASSERT ( I - eps <= M && M <= I + eps );

}
