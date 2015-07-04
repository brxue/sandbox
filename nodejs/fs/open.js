var fs= require("fs");

fs.open('/etc/bashrc', 'r', function(err, fd) {
    if (err) {
        return console.error(err);
    }
    console.log("File open successfully!")
    console.log("fd is a file descriptor in integer [" + fd + "]")
})
