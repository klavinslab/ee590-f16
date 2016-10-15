#include "matrix.hh"

using std::cout;
using std::endl;

int main ( int argc, char * argv[] ) {

  matrix A(3,3),
         B = matrix::random(3,3,-2,2);
  matrix C = B;
  matrix D = B + C + C;
  matrix I = matrix::identity(4),
         o = matrix::ones(4,4);

  matrix E(10);
  E.chop();

  cout << A << endl << B << endl;
  cout << D << endl;
  cout << D+D << endl;

  matrix Q = matrix::random(4,4,-2,2);
  cout << "Q:\n" << Q << endl;

  double d = Q.det();
  cout << "det(Q)= " << d << endl << endl;

  if ( d != 0 ) {
    matrix P = Q.inverse();
    matrix R = P*Q;
    cout << "Q^(-1):\n" << P << endl;
    cout << "Q*Q^(-1):\n" << R << endl;

    if ( I - o.scale(0.01) <= R && R <= I + o.scale(0.01) ) {
      cout << "Approximately equal!" << endl;
    } else {
      cout << "Not equal." << endl;
      cout << "I.scale(0.99):\n" << I - o.scale(0.01) << endl;
      cout << "I.scale(1.01):\n" << I + o.scale(0.01) << endl;
    }

  }

}
