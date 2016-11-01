#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Array a, b;

  for ( int i=0; i<10; i++ ) {
    Number n(i);
    a.set(i,n);
  }

  b = *(a.clone());

  Number n(-10);
  b.set(2,n);

  std::cout << a.stringify() << std::endl;
  std::cout << b.stringify() << std::endl;

  return 0;

}
