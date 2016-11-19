//LLRP DEVICE SCANNER
var net    = require('net'), Socket = net.Socket;

var checkPort = function(port, host, callback) {

    var socket = new Socket(), status = null;

    socket.on('connect', function() {status = 'open';socket.end();});
    socket.setTimeout(1500);// If no response, assume port is not listening
    socket.on('timeout', function() {status = 'closed';socket.destroy();});
    socket.on('error', function(exception) {status = 'closed';});
    socket.on('close', function(exception) {callback(null, status,host,port);});
    socket.connect(port, host);

}

var LAN = '173.250.236'; //Local area network to scan
var PORT = 8080;         //globally recognized LLRP port for RFID readers

//scan over a range of IP addresses and execute a function each time the LLRP port is shown to be open.
for(var i=1; i <=255; i++){
    checkPort(PORT, LAN+'.'+i, function(error, status, host, port){
        if(status == "open"){
            console.log("Server found: ", host, port, status);
        }
    });
}
