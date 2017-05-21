var Point = (
    function() {
        function Point(x, y) {
            this.x = x;
            this.y = y;
        }

        Point.prototype.scale = function(k) {
            this.x = k * this.x;
            this.y = k * this.y;
        }

        Point.ZERO = new Point(0, 0);
        Point.ONE = new Point(1, 1);

        return Point;
    }()
)

var p1 = new Point(2, 3);
p1.scale(2);
console.log(p1);
