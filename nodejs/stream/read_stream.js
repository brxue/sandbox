var fs = require("fs");
var data = '';

// Create a readable stream
var readerStream = fs.createReadStream('/etc/redhat-release');

// Set the encoding to be utf8. 
readerStream.setEncoding('UTF8');

// Register event handler on 'data' event
readerStream.on('data', function(chunk) {
    data += chunk;
});

// Register event handler on 'end' event
readerStream.on('end',function(){
    console.log(data);
});

// Register event handler on 'error' event
readerStream.on('error', function(err){
    console.log(err.stack);
});

console.log("Program Ended");
