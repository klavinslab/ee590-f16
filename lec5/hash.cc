#include "json.hh"

Hash::Hash() {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

}

Hash::~Hash() {

  Bucket * b, * c;

  for ( int i = 0; i<num_shelves; i++ ) {
    b = shelves[i];
    while ( b != NULL ) {
      delete b->value;
      c = b->next;
      delete b;
      b = c;
    }
  }

}

Array Hash::keys() const {

  Array a;
  Bucket * b;
  int j = 0;

  for ( int i = 0; i<num_shelves; i++ ) {

    b = shelves[i];

    while ( b ) {

      String s(shelves[i]->key);
      a.set(j,s);
      j++;
      b = b->next;
    }

  }

  return a;

}

Hash::Hash ( const Hash &hash ) {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

  Array k = hash.keys();

  for ( int i=0; i<k.length(); i++ ) {
    Object * key = k.get(i);
    if ( !key->is_null() ) {
      std::string key_str = ((String *) key)->string();
      set(key_str,hash.get(key_str));
    }
  }

}

void Hash::set ( std::string key, Object &value ) {
  set ( key, value.clone() );
}

void Hash::set ( std::string key, Object * value ) {

  // TODO: Homework: Use delete if key exists to avoid duplicate keys
  //       or reset the value in place (make sure to delete old value!)

  int i = hash(key);
  Bucket * ptr = new Bucket;

  ptr->key = key;
  ptr->value = value;
  ptr->next = shelves[i];
  shelves[i] = ptr;

}

Object * Hash::get ( std::string key ) const {

  int i = hash(key);
  Bucket * ptr = shelves[i];

  while ( ptr && ptr->key != key ) {
    ptr = ptr->next;
  }

  if ( ptr ) {
    return ptr->value;
  } else {
    throw "No value for key";
  }

}

int Hash::hash ( std::string s ) const {

  int n = 0;

  for ( int i=0; i<s.length(); i++ ) {
    n += (int) s[i];
  }

  return n % num_shelves;

}

std::string Hash::stringify() {

  std::string s = "{";

  for ( int i=0; i<num_shelves; i++ ) {
    Bucket * ptr = shelves[i];
    while ( ptr != NULL ) {
      s += "\"" + ptr->key + "\":" + ptr->value->stringify() + ",";
      ptr = ptr->next;
    }
  }

  if ( s[s.length()-1] == ',' ) {
    s[s.length()-1] = '}';
  } else {
    s += "}";
  }

  return s;

}
