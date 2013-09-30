syms x; % declare x as a symbol
f = sin(x) % function to be differentiated
diff(f) % first order differentiation

clear
syms x
f = sin(x)
diff(diff(f)) % second order differentiation
diff(f, 2) % another way to do second differentiation

clear
const5 = sym('5') % declare a const
diff(const5)

clear
syms x y
f = sin(x*y)
diff(f, x) % partial derivative to x
diff(f, y) % partial derivative to y
diff(f, x, 2) % second order partial derivative to x

clear
syms t
% parameter function
x = cos(t)
y = sin(t)
dydx = diff(y, t)/diff(x, t)