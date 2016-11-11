Tokenizer = require('./tokenizer.js')

function Parser(str) {

  this.str = str; // the string to be parsed

  this.tokenizer = new Tokenizer();

  this.tokenizer
      .add(/\+/)
      .add(/-/); // Add tokens here

}

Parser.prototype.factor = function() {
  // TODO
}

Parser.prototype.term = function() {
  // TODO
}

Parser.prototype.exr = function() {
  // TODO
}

Parser.prototype.parse = function() {
  // TODO
}

module.exports = Parser;
