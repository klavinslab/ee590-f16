let net = require('net');

function JSONSocket(socket) {

  var jsocket;

  if ( socket ) {
    jsocket = socket;
  } else {
    jsocket = new net.Socket();
  }

  jsocket.on('data',function(chunk) {

    var str = chunk.toString();
    var object;

    try {
      object = JSON.parse(str);
    } catch(err) {
      jsocket.emit('json_error', err);
      return;
    }

   jsocket.emit('json', object);

  });

  jsocket.jwrite = function(object,then) {
    return jsocket.write(JSON.stringify(object),then);
  }

  jsocket.error = function(message) {
    jsocket.jwrite({error: message});
  }

  return jsocket;

}

class JSONServer extends net.Server {

  constructor() {

    super();
    var server = this;

    server.on('connection',function(socket) {
      var jsocket = JSONSocket(socket);
      server.emit('json_connection', jsocket);
    })

  }

}

module.exports = {
  JSONServer: JSONServer,
  JSONSocket: JSONSocket
}
