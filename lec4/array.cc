#include "array.hh"
#include "null.hh"

Array::Array() {
  max = 10;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = NULL;
  }
}

Array::Array ( const Array &array ) {

  max = array.max;
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = array.values[i];
  }

}

void Array::set(int index, Object &object) {
  values[index] = object.clone();
}

Object* Array::get(int index) {
  if ( 0 <= index && index < max && values[index] != NULL ) {
    return values[index];
  } else {
    return new Null;
  }
}

std::string Array::stringify() {

  std::string s = "[";

  int m = 0;

  for ( int i=0; i<max; i++ ) {
    if ( values[i] != NULL ) {
      m = i;
    }
  }

  for ( int i=0; i<=m; i++ ) {
    if ( values[i] != NULL ) {
      s += values[i]->stringify();
    } else {
      s += "null";
    }
    if ( i < m ) {
      s += ",";
    }
  }

  s += "]";

  return s;

}
