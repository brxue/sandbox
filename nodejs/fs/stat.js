var fs = require("fs");

fs.stat('/etc/bashrc', function (err, stats) {
   if (err) {
       return console.error(err);
   }
   console.log(stats);
   console.log("isFile ? " + stats.isFile());
   console.log("isDirectory ? " + stats.isDirectory());    
   console.log("isSymbolicLink ? " + stats.isSymbolicLink());    
});
