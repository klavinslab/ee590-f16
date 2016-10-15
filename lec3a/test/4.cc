#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  // ASSIGNMENT OVERLOAD
  // This code tests the assignment '=' overload. In the for loop, the
  // named random matrix constructor produces a matrix that goes out of scope
  // when the for loop exits. So if there is no copying happening in the 'Q ='
  // part, then if you refer to Q after the for loop block, you'd be refering
  // to something that was deleted.

  matrix Q = matrix::random(4,4,-2,2);

  for ( int i=1; i<10; i++ ) {
    Q = matrix::random(4,4,-2,2);
  }

  SUCCEED; // This would fail if '=' were not defined because the destructor
           // for Q would be called. But Q would be (as a reference) equal to
           // the last random matrix made, which would already have been
           // deleted.
}
