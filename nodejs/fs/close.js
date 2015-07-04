var fs= require("fs");

fs.open('/etc/bashrc', 'r', function(err, fd) {
    if (err) {
        return console.error(err);
    }
    console.log("File open successfully!")

    fs.close(fd, function(err) {
        if (err) cosole.log(err)
        console.log("File closed successfully!")
    })
})
