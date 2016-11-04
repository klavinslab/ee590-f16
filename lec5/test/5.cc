#include <iostream>
#include <fstream>
#include <sstream>
#include "json.hh"

int main ( int argc, char * argv[] ) {

  std::ifstream inFile;
  inFile.open("data2.json"); //open the input file

  std::stringstream strStream;
  strStream << inFile.rdbuf(); //read the file
  std::string str = strStream.str(); //str holds the content of the file

  Parser p(str);

  Object * object = p.object();

  std::cout << object->stringify() << std::endl;


}
