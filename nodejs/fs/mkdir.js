var fs = require("fs");

fs.mkdir('/tmp/test',function(err){
   if (err) {
       return console.error(err);
   }
   console.log("Directory created successfully!");

   fs.stat('/tmp/test', function (err, stats) {
      if (err) {
          return console.error(err);
      }
      console.log("isDirectory ? " + stats.isDirectory());    
   });
});


