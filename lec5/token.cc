#include <string>
#include <iostream>

#include "token.hh"

std::string Token::to_s ( void ) {

  switch ( token_type ) {

  case PUNCTUATION: {
    std::string s("");
    s += punctuation;
    return s;
  }
  case STRING:
    return str;
  case BOOLEAN:
    return boolean ? std::string("true") : std::string("false");
  case NUMBER:
    return std::to_string(number);
  case NULLTOK:
    return std::string("null");
  default:
    return std::string("UNKNOWN TOKEN");
  }

}

std::ostream& operator<<(std::ostream& os, const Token &tok) {

  switch ( tok.type() ) {

  case Token::NULLTOK:
    os << "NULLTOK: null";
    break;

  case Token::NUMBER:
    os << "NUMBER: " << tok.number;
    break;

  case Token::STRING:
    os << "STRING: " << tok.str;
    break;

  case Token::BOOLEAN:
    os << "BOOLEAN: " << ( tok.boolean ? "true" : "false" );
    break;

  case Token::PUNCTUATION:
    os << "PUNCTUATION: " << tok.punctuation;
    break;

  default:
    os << "!UNKNOWN TOKEN!";
    break;

  }
  return os;

}
