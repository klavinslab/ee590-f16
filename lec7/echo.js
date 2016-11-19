let net = require('net');
let server = new net.Server();

server.on('connection',function(socket) {

  console.log('Connected to new client ' + JSON.stringify(socket.address()));

  socket.on('end', function(chunk) {
    console.log("Closing connection")
  });

  socket.on('data', function(chunk) {
     var str = chunk.toString();
     console.log("Received a message: " + str);
     socket.write("You said " + str);
     if ( str.match(/^end\s*$/) ) {
       console.log("Disconnecting from " +  JSON.stringify(socket.address()));
       socket.end('goodbye\n');
     }
  });

  socket.on('timeout', function() {
    console.log("Disconnecting from " + JSON.stringify(socket.address()) + " due to inactivity.");
    socket.end('goodbye\n');
  });

  socket.setTimeout(60*1000);

});

server.on('error', (err) => {
  throw err;
});

server.listen(8080, () => {
  console.log('server bound');
});
