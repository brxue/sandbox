var fs = require('fs');

fs.readFile('/etc/bashrc', function(err, data) {
    if (err) {
        return console.error(err);
    }
    console.log("Asynchronous read: \n");
    console.log(data.toString().substring(0, 100));
})

console.log("Hello, I'm printed before file read finished!");
