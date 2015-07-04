var fs = require("fs");

fs.open('/etc/bashrc', 'r', function(err, fd) {
   if (err) {
       return console.error(err);
   }
   console.log("File opened successfully!");
   
   // Read the opened file: 256 bytes
   var buf = new Buffer(256);
   fs.read(fd, buf, 0, buf.length, 0, function(err, bytes){
      if (err){
         console.log(err);
      }
      console.log(bytes + " bytes read");
      
      // Only print when the number of bytes read is larger than 0
      if(bytes > 0){
         console.log(buf.slice(0, bytes).toString());
      }
   });
});
