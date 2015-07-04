var events = require('events');

var producer = new events.EventEmitter();
var consumer = new events.EventEmitter();

producer.on('sent', function sent(){
    console.log('data sent out');
    consumer.emit('received');
})

consumer.on('received', function(){
   console.log('data received succesfully.');
});

producer.emit('sent');

console.log("Program Ended.");
