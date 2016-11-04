#include "array.hh"
#include "null.hh"

Array::Array() : max(10) {
  values = new Object *[max];
  for ( int i=0; i < max; i++ ) {
    values[i] = new Null;
  }
}

Array::Array ( const Array &array ) {

  max = array.max;
  values = new Object *[max];

  for ( int i=0; i < max; i++ ) {
    values[i] = array.values[i]->clone();
  }

}

Array &Array::operator=(const Array &other) {

  Object ** temp;

  if ( this != &other ) {

    max = other.max;
    temp = new Object *[max];

    for ( int i=0; i < max; i++ ) {
      temp[i] = other.values[i]->clone();
    }

    delete []values;
    values = temp;

  }

  return *this;

}

Array::~Array() {

  for ( int i = 0; i<max; i++ ) {
    delete values[i];
  }

  delete []values;

}

void Array::resize(int m) {

  Object ** temp = new Object*[m];
  int i;

  for ( i=0; i<max; i++ ) {
    temp[i] = values[i];
  }

  for ( i=max; i<m; i++ ) {
    temp[i] = new Null;
  }

  delete []values;
  values = temp;
  max = m;

}

void Array::set(int index, Object &object) {

  set ( index, object.clone() );

}

void Array::set(int index, Object * object) {

  if ( index < 0 ) {
    throw "Array out of bounds";
  } else if ( index >= max ) {
    resize(index + 10);
  }

  if ( values[index] != NULL ) {
    delete values[index];
  }

  values[index] = object;

}

Object* Array::get(int index) const {
  if ( 0 <= index && index < max && values[index] != NULL ) {
    return values[index];
  } else {
    throw "Array out of bounds";
  }
}

std::string Array::stringify() {

  std::string s = "[";

  int m = -1;

  for ( int i=0; i<max; i++ ) {
    if ( !values[i]->is_null() ) {
      m = i;
    }
  }

  for ( int i=0; i<=m; i++ ) {
    s += values[i]->stringify();
    if ( i < m ) {
      s += ",";
    }
  }

  s += "]";

  return s;

}
