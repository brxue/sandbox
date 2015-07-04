var fs = require('fs');

fs.readFile('/etc/bashrc', function(err, data) {
    if (err) {
        return console.error(err);
    }
    console.log("Asynchronous read: \n");
    console.log(data.toString().substring(0, 100));
})

var text = fs.readFileSync('/etc/profile')
console.log("Synchronous read: \n");
console.log(text.toString().substring(0, 100));
