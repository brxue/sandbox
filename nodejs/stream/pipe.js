var fs = require("fs");

// Create a readable stream
var readerStream = fs.createReadStream('/etc/redhat-release');

// Create a writable stream
var writerStream = fs.createWriteStream('output.txt');

// Pipe the read and write operations
// read `/etc/redhat-release` and write data to 'output.txt'
readerStream.pipe(writerStream);

console.log("Program Ended");
