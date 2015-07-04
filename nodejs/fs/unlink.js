var fs = require("fs");

fs.writeFile('temp.txt', "Hello World!", function(err) {
   if (err) console.log(err)
   console.log("The content of temp.txt is: " + fs.readFileSync('temp.txt').toString());

   fs.stat('temp.txt', function (err, stats) {
      if (err) return console.error(err);
      console.log("isFile ? " + stats.isFile());
   });

   fs.unlink('temp.txt', function(err) {
      if (err) {
          return console.error(err);
      }
      console.log("File deleted successfully!");
   });
});
