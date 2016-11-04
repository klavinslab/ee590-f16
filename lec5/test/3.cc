#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Parser p("[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]");

  std::cout << p.object()->stringify() << std::endl;

  return 0;

}
