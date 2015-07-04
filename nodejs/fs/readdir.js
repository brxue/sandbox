var fs = require("fs");

fs.readdir("/bin", function(err, files){
   if (err) {
       return console.error(err);
   }
   files.forEach(function (file, idx){
       if (file == 'ls' || file == 'mv'){ 
          console.log(file);
       }
   });
});
