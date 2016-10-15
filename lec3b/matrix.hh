#include <iostream>
#include <stdexcept>

class matrix_exception : public std::runtime_error {
public:
  matrix_exception(const char msg[]) : std::runtime_error(msg) { }
};

template <class T>
class matrix {

public:

  matrix(int r, int c);
  ~matrix();

  matrix add ( const matrix &m ) const;
  void set(int r, int c, T x);
  T get(int r, int c) const;
  inline int rows(void) const { return num_rows; }
  inline int columns(void) const { return num_columns; }
  bool in_range(int r, int c) const;

private:
  int num_rows, num_columns;
  T * value;

};

// Interface with ostreams
template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T> &m);

#include "matrix.impl.hh"
