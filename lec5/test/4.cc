#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  Object * x = new Null;

  Hash h;
  Number n(3.14159);

  std::cout << x->is_null() << std::endl;

  h.set("first",  n);
  h.set("second", n);

  Array a = h.keys();
  std::cout << a.stringify() << std::endl;

  h.set("keys", a);
  std::cout << h.stringify() << std::endl;

  return 0;

}
