Tokenizer = require('./tokenizer.js');

t = new Tokenizer();

t.add(/\[/)
 .add(/\d+/)
 .add(/,/)
 .add(/]/)
 .tokenize("[ 100, 200,300, ,,[][]]");

console.log(t.tokens);
