#include "object.hh"

class Array : public Object {

public:

  Array();
  ~Array();

  Array ( const Array &array );
  Array& operator=(const Array &other);
  Array * clone() { return new Array(*this); }
  int length() { return max; }
  void resize(int m);

  void set(int index, Object &object);
  void set(int index, Object * object);

  Object * get(int index) const;
  std::string stringify();

private:

  int max;
  Object ** values;

};
