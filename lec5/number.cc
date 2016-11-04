#include "number.hh"

Number::Number(double d) : value(d) {
}

std::string Number::stringify() {
  if ( value - (int) value == 0 ) {
    return std::to_string((int)value);
  } else {
    return std::to_string(value);
  }
}
