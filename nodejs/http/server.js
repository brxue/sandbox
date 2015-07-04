var http = require('http');
var fs = require('fs');
var url = require('url');

http.createServer( function (request, response) {  
   var pathname = url.parse(request.url).pathname;
   console.log("Request for " + pathname + " received.");
   
   // Read the requested file content from file system
   var filename = pathname.substr(1)
   fs.readFile(filename, function (err, data) {
      if (err) {
         // console.log(err);
         // HTTP Status: 404 : NOT FOUND
         response.writeHead(404, {'Content-Type': 'text/html'}); // HTTP header
         response.write("The page you are requesting is NOT found."); // HTTP body
      }else{	
         // HTTP Status: 200 : OK
         response.writeHead(200, {'Content-Type': 'text/html'}); // HTTP header
         response.write(data.toString()); // HTTP body
      }
      response.end();// Send the response
   });   
}).listen(8888);

console.log('Server running at http://127.0.0.1:8888/');
