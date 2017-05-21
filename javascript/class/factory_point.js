function point(x, y) {
    var p = Object.create(point.methods);
    p.x = x;
    p.y = y;
    return p;
}

point.methods = {
    add: function(p) {return point(p.x + this.x, p.y + this.y)},
    minus: function(p) {return point(p.x - this.x, p.y - this.y)},
}

point.ZERO = point(0, 0);

var p1 = point(3, 4);
var p2 = point(6, 8);

console.log(p1);
console.log(p2);
console.log(p1.add(p2));
console.log(p1.add(point.ZERO));
