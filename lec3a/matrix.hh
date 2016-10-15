#include <iostream>
#include <stdexcept>

class matrix_exception : public std::runtime_error {
public:
  matrix_exception(const char msg[]) : std::runtime_error(msg) { }
};

class matrix {

public:

  // Constructors and destructors
  matrix(int r, int c);
  matrix(int s) : matrix(s,s) {};
  ~matrix();

  // Named constructors
  static matrix random( int r, int c, int min, int max );
  static matrix identity( int s );
  static matrix ones ( int r, int c );

  // The copy constructor
  matrix ( const matrix &m );
  matrix& operator=(const matrix &other);

  // Setters
  void set(int r, int c, double x);

  // Getters (note const after arguments)
  double get(int r, int c) const;
  inline int rows(void) const { return num_rows; }
  inline int columns(void) const { return num_columns; }
  bool in_range(int r, int c) const;

  // Operations
  matrix add ( const matrix &m ) const;
  matrix mult ( const matrix &m ) const;
  void scale ( double d );
  bool equals ( const matrix &m ) const;
  bool less_than ( const matrix &m ) const;

  inline matrix operator+(const matrix &m) { return add(m); }
  inline matrix operator-(const matrix &m) { matrix temp = m; temp.scale(-1); return add(temp); }
  inline matrix operator*(const matrix &m) { return mult(m); }
  inline bool operator==(const matrix &m) { return equals(m); }
  inline bool operator!=(const matrix &m) { return !equals(m); }

  inline bool operator<(const matrix &m) { return less_than(m); }
  inline bool operator>(const matrix &m) { return m.less_than(*this); }
  inline bool operator<=(const matrix &m) { return less_than(m) || equals(m); }
  inline bool operator>=(const matrix &m) { return m.less_than(*this) || m.equals(*this); }

  matrix minor ( int r, int c );
  matrix inverse();
  double det(void);

private:

  double * value;
  int num_rows,
      num_columns;

};

// Interface with ostreams
std::ostream& operator<<(std::ostream& os, const matrix &m);
