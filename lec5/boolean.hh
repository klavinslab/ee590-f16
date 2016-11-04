#include "object.hh"

class Boolean : public Object {

public:

  Boolean(bool b) : value(b) {}
  Boolean ( const Boolean &b ) { value = b.value; }

  Boolean * clone() { return new Boolean(*this); }
  std::string stringify() { return value ? "true" : "false"; }

private:

  bool value;

};
