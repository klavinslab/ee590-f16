#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Number number(1.0);
  Array array;

  array.set(0,number);
  number.set(2.0);
  array.set(1,number);
  array.set(3,array);

  std::cout << number.stringify() << std::endl;
  std::cout << array.stringify() << std::endl;
  std::cout << array.get(3)->stringify() << std::endl;

  return 0;

}
