#ifndef _HASH_H_
#define _HASH_H_

#include "json.hh"

typedef struct _Bucket {
  std::string key;
  Object * value;
  _Bucket * next;
} Bucket;

class Hash : public Object {

public:

  Hash();
  ~Hash();
  Hash ( const Hash &hash );

  Array keys() const;

  Hash * clone() { return new Hash(*this); }
  void set ( std::string key, Object &value);
  void set ( std::string key, Object * value);
  Object * get ( std::string key ) const;
  std::string stringify();


private:

  int hash ( std::string s ) const;
  static const int num_shelves = 256;
  Bucket * shelves[num_shelves];

};

#endif
