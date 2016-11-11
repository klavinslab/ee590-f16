Tokenizer = require('./tokenizer.js');

t = new Tokenizer();

t.add(/\[/)
 .add(/\d+/)
 .add(/,/)
 .add(/]/)
 .tokenize("[1,2,3]");

console.log(t.tokens);
