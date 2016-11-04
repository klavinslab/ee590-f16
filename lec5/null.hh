#ifndef _NULL_H_
#define _NULL_H_

#include "object.hh"

class Null : public Object {

public:

  Null() {}

  Null * clone() { return new Null(*this); }
  bool is_null() { return true; }

  std::string stringify() { return std::string("null"); }

};

#endif
