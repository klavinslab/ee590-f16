#include <iostream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  //Tokenizer tok("{ \"first\": [ true, \"a\", \"b\", \"c\" ], \"second\": 1.234 }");

  Tokenizer tok("{ \"a\": [0,1,2], \"b\": { \"c\": 0 } }");

  while ( !tok.eof() ) {
    std::cout << tok.eat() << std::endl;
  }

  return 0;

}
