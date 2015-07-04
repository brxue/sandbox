var fs = require('fs');

var text = fs.readFileSync('/etc/profile')
console.log("Synchronous read: \n");
console.log(text.toString().substring(0, 100));
