function Complex(real, imaginary) {
    if (isNaN(real) || isNaN(imaginary)) // Ensure that both args are numbers.
        throw new TypeError();

    this.r = real;
    this.i = imaginary;
}

Complex.prototype.add = function(that) {
    return new Complex(this.r + that.r, this.i + that.i);
};

Complex.prototype.mul = function(that) {
    return new Complex(this.r * that.r - this.i * that.i, this.r * that.i + this.i * that.r);
};

Complex.prototype.mag = function() {
    return Math.sqrt(this.r*this.r + this.i*this.i);
};

Complex.prototype.neg = function() { 
    return new Complex(-this.r, -this.i); 
};

Complex.prototype.toString = function() {
    return "{" + this.r + "," + this.i + "}";
};

Complex.prototype.equals = function(that) {
    return that != null && that.constructor === Complex && this.r === that.r && this.i === that.i;
};

Complex.ZERO = new Complex(0,0);
Complex.ONE = new Complex(1,1);

// ---------------------------------------------------

var c1 = new Complex(3, 4);
var c2 = new Complex(c1.r, c1.i);

console.log(c1.add(c2).toString());
console.log(c1.equals(c2));
console.log(c1.mag());
console.log(c1.add(Complex.ONE).toString());
