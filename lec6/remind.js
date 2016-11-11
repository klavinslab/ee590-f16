function Reminder(duration,times) {

    var si,
        n = times ? times : 1,
        reminder = this;

    function say() {        
	console.log("The time is " + Date());
        if ( --n == 0 ) {
	    reminder.stop();
        }
    }

    this.start = function() {
      si = setInterval(say,duration);
    }

    this.stop = function() {
	clearInterval(si);
    }

}

var r = new Reminder(1000,1);
r.start();