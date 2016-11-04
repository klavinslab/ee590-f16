#include "object.hh"

class String : public Object {

public:

  String(std::string s);
  String ( const String &s ) { value = s.value; }

  String * clone() { return new String(*this); }
  inline void set(std::string d) { value = d; }

  inline std::string string() { return value; }

  std::string stringify();

private:

  std::string value;

};
