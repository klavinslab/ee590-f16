#include <iostream>
#include <math.h>
#include "matrix.hh"

matrix matrix::add ( const matrix &m ) const {

  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to add matrices with incompatible sizes");
  }

  matrix M(rows(),columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      M.set(i,j,get(i,j) + m.get(i,j));
    }
  }

  return M;

}

matrix matrix::mult ( const matrix &m ) const {

  if ( columns() != m.rows() ) {
    throw matrix_exception("Attemped to multiple matrices with incompatible sizes");
  }

  matrix M(rows(),columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      M.set(i,j,0);
      for ( int k=0; k<columns(); k++ ) {
        M.set(i,j,M.get(i,j) + get(i,k) * m.get(k,j));
      }
    }
  }

  return M;

}

void matrix::scale ( double d ) {
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      set(i,j,d*get(i,j));
    }
  }
}

matrix matrix::minor ( int r, int c ) {

  if ( !in_range(r,c) ) {
    throw matrix_exception("Attempted to take minor with out of range indices");
  }

  matrix p ( rows() - 1, columns() - 1 );

  int I, J;

  for ( int i=0, I=0; i<rows(); i++ ) {
    for ( int j=0, J=0; j<columns(); j++ ) {
      if ( i != r && j != c ) {
        p.set(I,J,get(i,j));
        J++;
      }
    }
    if ( i != r ) {
      I++;
    }
  }

  return p;

}

double matrix::det(void) {

  if ( rows() == 1 && columns() == 1 ) {

    return get(0,0);

  } else {

    double sign = 1, sum = 0;

    for ( int i=0; i<columns(); i++ ) {
      sum += sign * get(0,i) * minor(0,i).det();
      sign *= -1;
    }

    return sum;

  }

}

matrix matrix::inverse ( void ) {

  matrix m(rows(),columns());

  if ( rows() != columns() ) {
    throw matrix_exception("Attempted to invert non-square matrix");
  }

  double d = det();

  if ( d == 0 ) {
    throw matrix_exception("Attempted to invert non-invertible matrix");
  }

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      int sign = ( (i+j)%2 == 0 ) ? 1 : -1;
      m.set(i,j,sign*minor(j,i).det()/d);
    }
  }

  return m;

}

bool matrix::equals ( const matrix & m ) const {
  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      if ( get(i,j) != m.get(i,j) ) {
        return false;
      }
    }
  }
  return true;
}

bool matrix::less_than ( const matrix & m ) const {
  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      if ( get(i,j) >= m.get(i,j) ) {
        return false;
      }
    }
  }
  return true;
}
