let jnet  = require('./json_net');

let client = jnet.JSONSocket();

function send() {

  setTimeout(function() {

    if ( Math.random() > 0.5 ) {
      client.jwrite({ command: "push", value: Math.floor(Math.random()*100) }, send);
    } else {
      client.jwrite({ command: "pop"},send);
    }

  }, 1000 );

}

client.on('connect', function() {
  send();
});

client.on('json', function(object) {
  console.log(object);
});

client.on('error', (err) => {
  throw err;
});

client.connect(8080, 'localhost');
