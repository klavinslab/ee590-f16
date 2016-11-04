#include "json.hh"

Tokenizer::Tokenizer(std::string data) : buffer(data), i(0) {
}

bool Tokenizer::eof() {
  whitespace();
  return i >= buffer.length();
}

bool Tokenizer::is_ws(char c) {
   return c == ' ' || c == '\n' || c == '\r' || c == '\t';
}

bool Tokenizer::is_num(char c) {
   return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
       || c == '6' || c == '7' || c == '8' || c == '9';
}

void Tokenizer::whitespace() {

  while ( i < buffer.length() && is_ws(buffer[i]) ) {
    i++;
  }
}

Token Tokenizer::eat_symbol(const std::string s) {

  int j = 0;
  std::string read("");

  while ( buffer[i] == s[j] && i < buffer.length() && s[j] != '\0' ) {
    read += buffer[i];
    i++;
    j++;
  }

  if ( read != s ) {
    std::string err = "Expected symbol ";
    err += s;
    err += " but encountered ";
    err += read;
    throw TokenizerException(err.c_str());
  }

  return Token(s);

}

Token Tokenizer::eat_punctuation ( char c ) {

  if ( current().matches(c) ) {
    return eat();
  } else {
    std::string err("Expected token ");
    err += c;
    err += " but encountered ";
    err += buffer[i];
    throw TokenizerException(err.c_str());
  }

}

Token Tokenizer::string() {

  std::string str;

  i++;

  while ( !eof() && buffer[i] != '"' ) {
    if ( buffer[i] == '\\' ) {
      str += buffer[i++];
    }
    str += buffer[i++];
  }

  i++;

  return Token(str);

}

Token Tokenizer::number() {

  // TODO: Accept negative numbers, and exponents like 10e3 or 16e-3.

  std::string s("");

  while ( is_num(buffer[i]) ) {
    s += buffer[i++];
  }

  if ( buffer[i] == '.' ) {
    s += buffer[i++];
    while ( is_num(buffer[i]) ) {
      s += buffer[i++];
    }
  }

  return Token(std::stod(s));

}

Token Tokenizer::next() {

  // skip white space
  whitespace();

  if ( eof() ) {
    throw TokenizerException("Unexpected EOF");
  }

  switch ( buffer[i] ) {
  case '{':
  case '}':
  case '[':
  case ']':
  case ':':
  case ',':
    return Token(buffer[i++]);
  case '"':
    return string();
  case 'n':
    eat_symbol("null");
    return Token();
  case 't':
    eat_symbol("true");
    return Token(true);
  case 'f':
    eat_symbol("false");
    return Token(false);
  default:
    if ( is_num(buffer[i]) || buffer[i] == '.' ) {
      return number();
    } else {
      std::string err("Unexpcted character: '");
      err += buffer[i];
      err += "'";
      throw TokenizerException(err.c_str());
    }
  }

}

Token Tokenizer::eat() {

  if ( !eof() ) {
    current_token = next();
  }
  return current_token;
}

Token Tokenizer::current() {

  if ( i == 0 ) {
    current_token = next();
  }

  return current_token;

}
