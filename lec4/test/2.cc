#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Hash h;
  Number n(1);

  h.set("first", n);
  h.set("second", h);

  std::cout << h.stringify() << std::endl;
  std::cout << h.get("first")->stringify() << std::endl;
  std::cout << h.get("second")->stringify() << std::endl;

  // next line will fail until the copy constructor for Hash is implemented
  std::cout << h.get("second")->get("first")->stringify() << std::endl;

  return 0;

}
