#include "hash.hh"
#include "null.hh"

Hash::Hash() {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

}

Hash::Hash ( const Hash &hash ) {

  for ( int i=0; i<num_shelves; i++ ) {
    shelves[i] = NULL;
  }

  // TODO: method keys() that returns an Array of keys
  //           for ( k in keys() ) {
  //             set(k,hash.get(k))
  //           }

}

void Hash::set ( std::string key, Object &value ) {

  // TODO: Homework: Use delete if key exists to avoid duplicate keys
  //       or reset the value in place (make sure to delete old value!)

  int i = hash(key);

  Bucket * ptr = new Bucket;

  ptr->key = key;
  ptr->value = value.clone();
  ptr->next = shelves[i];
  shelves[i] = ptr;

}

Object * Hash::get ( std::string key ) {

  DEBUG("getting " + key);

  int i = hash(key);

  Bucket * ptr = shelves[i];

  DEBUG("1");

  while ( ptr && ptr->key != key ) {
    ptr = ptr->next;
  }

  DEBUG("2");

  if ( ptr ) {
    DEBUG("3");
    return ptr->value;
  } else {
    DEBUG("4");
    throw "No value for key";
  }

}

int Hash::hash ( std::string s ) {

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
      s += ptr->key + ":" + ptr->value->stringify() + ",";
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
