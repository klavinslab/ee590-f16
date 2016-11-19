const EventEmitter = require('events');

class Ticker extends EventEmitter {

  constructor(period) {

    super();

    var ticker = this;
    ticker.period = period;
    ticker.n = 0;

    setInterval(function() {
      ticker.emit('tick',ticker.n++);
    },period);

  }

}

t = new Ticker(1000);

t.on('tick', function(n) {
  console.log("Tick #" + n);
});

t.prependListener('tick', function(n) {
  console.log("Another Tick #" + n);
});

console.log("Set up complete");
