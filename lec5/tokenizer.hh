#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include <iostream>
#include <string>
#include "token.hh"

class TokenizerException : public std::runtime_error {
public:
  TokenizerException(const char msg[]) : std::runtime_error(msg) {}
};

class Tokenizer {

public:

  Tokenizer(std::string data);

  Token current();                    // returns the current token
  Token eat();                        // advances to the next
  Token eat_punctuation(char c);      // checks that the current token is c and eats it
  Token eat_symbol(const std::string s);   // checks that the current token matches s and eats it

  bool eof();

private:

  std::string buffer;
  int i;
  Token current_token;

  Token next();
  Token string();
  Token number();
  void whitespace();
  bool is_num(char c);
  bool is_ws(char c);

};

#endif
