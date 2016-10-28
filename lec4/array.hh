#include "object.hh"

class Array : public Object {

public:

  Array();
  Array ( const Array &array );
  Array * clone() { return new Array(*this); }

  void set(int index, Object &object);
  Object * get(int index);
  std::string stringify();

private:

  int max;
  Object ** values;

};
