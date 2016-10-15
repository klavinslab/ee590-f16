
template <class T>
matrix<T>::matrix ( int r, int c ) : num_rows(r), num_columns(c) {

  if ( r <= 0 || c <= 0 ) {
    throw matrix_exception("Attempted to initialize a matrix with non-positive number of rows and/or columns");
  }

  value = new T[r*c];

  for ( int i=0; i<r*c; i++ ) {
    value[i] = (T) 0;
  }

}

template <class T>
matrix<T>::~matrix() {
  delete []value;
}

template <class T>
matrix<T> matrix<T>::add ( const matrix &m ) const {

  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to add matrices with incompatible sizes");
  }

  matrix M(rows(),columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      M.set(i,j,(T) (get(i,j) + m.get(i,j))); /* NOTE: Casting result back to T */
    }
  }

  return M;

}

template <class T>
T matrix<T>::get(int r, int c) const {

  if ( !in_range(r,c) ) {
    throw matrix_exception("Indices out of range in matrix::get");
  }

  return value[r * columns() + c];

}

template <class T>
void matrix<T>::set(int r, int c, T x) {
  if ( !in_range(r,c) ) {
    throw matrix_exception("Indices out of range in matrix::set");
  }
  value[r * columns() + c] = x;
}

template <class T>
bool matrix<T>::in_range(int r, int c) const {
  return 0 <= r && r < rows() && 0 <= c && c < columns();
}

template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T> &m) {

  for ( int i=0; i<m.rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      os << m.get(i,j) << '\t';
    }
    os << std::endl;
  }

  return os;

}
