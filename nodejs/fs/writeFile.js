var fs = require("fs");

fs.writeFile('temp.txt', 'Hello World!',  function(err) {
   if (err) {
       return console.error(err);
   }
   console.log("Data was written successfully before entering this callback!");
   console.log("Let's read newly written data");
   fs.readFile('temp.txt', function (err, data) {
      if (err) {
         return console.error(err);
      }
      if (data.toString() != "Hello World!") {
          console.error("Error: this should not occurred!");
      } else {
        console.log("Asynchronous read: " + data.toString());
      }
   });
});
