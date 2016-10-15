#include "test.hh"
#include "matrix.hh"

int main ( int argc, char * argv[] ) {

  matrix<int> Q(2,2);

  Q.set(0,0,1); Q.set(0,1,2);
  Q.set(1,0,3); Q.set(1,1,4);

  matrix<int> M = Q.add(Q);

  return 0;

}
