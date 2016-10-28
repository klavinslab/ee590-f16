#include "number.hh"

Number::Number(double d) : value(d) {
}

std::string Number::stringify() {
  return std::to_string(value);
}
