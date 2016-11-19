var http = require('http');

stack = [];

http.createServer(function(request, response) {

  var body = [];

  function end(object) {
    response.end(JSON.stringify(object));
  }

  function error(string) {
    response.end(JSON.stringify({error: string}));
  }

  request.on('data', function(chunk) {

    body.push(chunk);

  }).on('end', function() {

    var raw = Buffer.concat(body).toString();

    try {
      var object = JSON.parse(raw);
    } catch (e) {
      console.log(e.message);
      error("JSON Format: " + e.message);
      return;
    }

    if ( object.command == 'push' ) {
      stack.push(object.value);
      end({ value: object.value });
    } else if ( object.command == 'pop' ) {
      if ( stack.length > 0 ) {
        end({value: stack.pop()});
      } else {
        error("Empty stack during 'pop'");
      }
    } else if ( object.command == 'top' ) {
      if ( stack.length > 0 ) {
        end({value: stack[stack.length-1]});
      } else {
        error("Empty stack during 'top'");
      }
    } else {
      error("Unknown command '" + object.command + "'");
    }

  });

}).listen(8080);
