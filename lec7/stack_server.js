let jnet = require('./json_net');
let Stack = require("./stack")

let server = new jnet.JSONServer();

server.stack = new Stack();

server.on('json_connection',function(jsocket) {

  var responses = {

    push: function(object) {
      server.stack.push(object.value);
      jsocket.jwrite({ value: object.value });
    },

    pop: function(object) {
      jsocket.jwrite({value: server.stack.pop()});
    },

    top: function(object) {
      if ( stack.length > 0 ) {
        jsocket.jwrite({value: server.stack[server.stack.length-1]});
      } else {
        jsocket.error("Empty stack during 'top'");
      }
    },

    end: function(object,socket) {
      jsocket.end();
    }

  }

  jsocket.on('json', function(object) {

    if ( responses[object.command] ) {
      responses[object.command](object);
    } else {
      jsocket.error("Unknown command '" + object.command + "'");
    }

    console.log(server.stack);

  });

});

server.on('error', (err) => {
  throw err;
});

server.listen(8080, () => {
  console.log('server bound');
});
