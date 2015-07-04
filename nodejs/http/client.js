var http = require('http');

var callback = function(response){
   var body = '';
   response.on('data', function(data) {
      // Continuously update stream with data
      body += data;
   });
   
   response.on('end', function() {
      // Data received completely.
      console.log(body);
   });
}

// Make a request to the server
var req = http.request({host: 'localhost', port: '8888', path: '/index.html'}, callback);
req.end();
