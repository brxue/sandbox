var fs = require("fs");

fs.rmdir("/tmp/test",function(err){
   if (err) {
       return console.error(err);
   }
   console.log("Directory /tmp/test removed successfully.");
});
