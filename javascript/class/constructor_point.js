function Point(x, y) {
    this.x = x;
    this.y = y;
}

Point.prototype = {
    add: function(p) {return new Point(p.x + this.x, p.y + this.y)}
}

Point.ZERO = new Point(0, 0);

var p1 = new Point(3, 4);
var p2 = new Point(6, 8);

console.log(p1);
console.log(p2);
console.log(p1.add(p2));
console.log(p1.add(Point.ZERO));
