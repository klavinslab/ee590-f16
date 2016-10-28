#include "object.hh"

class Null : public Object {

public:

  Null() {}

  Null * clone() { return new Null(*this); }
  std::string stringify() { return std::string("null"); }

};
