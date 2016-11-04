#ifndef _OBJECT_H_
#define _OBJECT_H_

#include <iostream>
#include <string>

class Object {

public:

  Object();
  Object ( const Object &m ) {}
  virtual ~Object() {}

  virtual Object * clone() = 0;
  virtual std::string stringify() = 0;
  virtual Object * get() const { throw "Undefined getter: get()"; }
  virtual Object * get(std::string s) const { throw "Undefined getter: get(s)"; }
  virtual Object * get(int i) const { throw "Undefined getter: get(i)"; }

  virtual bool is_null() { return false; }

};

#define DEBUG(_msg_) { std::cout << _msg_ << std::endl; }

#endif
