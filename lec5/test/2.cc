#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  std::ifstream inFile;
  inFile.open("data.json");//open the input file

  std::stringstream strStream;
  strStream << inFile.rdbuf();//read the file
  std::string str = strStream.str();//str holds the content of the file

  Tokenizer tok(str);

  while ( !tok.eof() ) {
    std::cout << tok.eat() << std::endl;
  }

  return 0;

}
