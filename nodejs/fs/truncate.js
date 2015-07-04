var fs = require("fs");
var buf = new Buffer(1024);

fs.writeFile('temp.txt', "Hello World!", function(err){
   if (err) console.log(err);
   console.log("The content of temp.txt is: " + fs.readFileSync('temp.txt').toString());

   fs.open('temp.txt', 'r+', function(err, fd) {
      if (err) return console.error(err);

      console.log("File opened successfully!");
      console.log("Going to truncate the file after 3 bytes");
      
      // Truncate the opened file.
      fs.ftruncate(fd, 3, function(err){
         if (err){
            console.log(err);
         } 
         console.log("File truncated successfully.");

         console.log("The content of temp.txt after truncated is: "); 
         fs.read(fd, buf, 0, buf.length, 0, function(err, bytes){
            if (err){
               console.log(err);
            }
   
            // Print only read bytes to avoid junk.
            if(bytes > 0){
               console.log(buf.slice(0, bytes).toString());
            }
   
            // Close the opened file.
            fs.close(fd, function(err){
               if (err){
                  console.log(err);
               } 
               console.log("File closed successfully.");
            });
         });
      });
   });
});
