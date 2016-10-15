#include <iostream>
#include "matrix.hh"

matrix::matrix ( int r, int c ) : num_rows(r), num_columns(c) {

  if ( r <= 0 || c <= 0 ) {
    throw matrix_exception("Attempted to initialize a matrix with non-positive number of rows and/or columns");
  }

  value = new double[r*c];

  for ( int i=0; i<r*c; i++ ) {
    value[i] = 0.0;
  }

}

matrix::~matrix() {
  delete []value;
}

matrix::matrix ( const matrix &m ) {

  num_rows = m.num_rows;
  num_columns = m.num_columns;
  value = new double[num_rows*num_columns];

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      set(i,j,m.get(i,j));
    }
  }

}

matrix &matrix::operator=(const matrix &other) {

  if ( this != &other ) {
    num_rows = other.num_rows;
    num_columns = other.num_columns;
    double * temp = new double[num_rows*num_columns];
    for ( int i=0; i<num_rows*num_columns; i++ ) {
      temp[i] = other.value[i];
    }
    delete []value;
    value = temp;
  }

  return *this;

}

double matrix::get(int r, int c) const {

  if ( !in_range(r,c) ) {
    throw matrix_exception("Indices out of range in matrix::get");
  }

  return value[r * columns() + c];

}

void matrix::set(int r, int c, double x) {
  if ( !in_range(r,c) ) {
    throw matrix_exception("Indices out of range in matrix::set");
  }
  value[r * columns() + c] = x;
}

matrix matrix::identity ( int s ) {

  matrix m(s);

  for ( int i=0; i<s; i++ ) {
    m.set(i,i,1.0);
  }

  return m;

}

matrix matrix::ones ( int r, int c ) {

  matrix m(r,c);

  for ( int i=0; i<r; i++ ) {
    for ( int j=0; j<c; j++ ) {
      m.set(i,j,1.0);
    }
  }

  return m;

}

matrix matrix::random( int r, int c, int min, int max ) {

  if ( r <= 0 || c <= 0 ) {
    throw matrix_exception("Attempted to build a random matrix with non-positive number of rows and/or columns");
  }

  if ( max <= min ) {
    throw matrix_exception("Min is not less than max when building a random matrix");
  }

  matrix m(r,c);
  int d = max - min + 1,
      h = d / 2;

  for ( int i=0; i<r; i++ ) {
    for ( int j=0; j<c; j++ ) {
      m.set(i,j,rand()%d-h);
    }
  }

  return m;

}

bool matrix::in_range(int r, int c) const {

  return 0 <= r && r < rows() && 0 <= c && c < columns();

}

std::ostream& operator<<(std::ostream& os, const matrix &m) {

  for ( int i=0; i<m.rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      os << m.get(i,j) << '\t';
    }
    os << std::endl;
  }

  return os;

}
