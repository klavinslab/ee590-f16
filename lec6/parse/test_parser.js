//
// Usage:
//   node test_parser.js "1.0 + 5.4/2"
//

Parser = require('./parser.js')
p = new Parser(process.argv[2])
console.log(process.argv[2] + " evaluates to " + p.parse());
