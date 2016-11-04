#include "string.hh"

String::String(std::string s) : value(s) {
}

std::string String::stringify() {
  std::string s = "\"" + value + "\"";
  return s;
}
