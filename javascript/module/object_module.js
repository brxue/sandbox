var point = {};

point.Point = function(x, y) {
    this.x = x;
    this.y = y;
}

point.Point.prototype.scale = function(k) {
    this.x = k * this.x;
    this.y = k * this.y;
}

point.ZERO = new point.Point(0, 0);
point.ONE = new point.Point(1, 1);

// ---------------------------------

var p1 = new point.Point(1, 2);
p1.scale(2);
console.log(p1);
