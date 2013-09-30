syms x a
f = sin(a*x)
int(f, x) % infinite integral
int(f, x, 0, pi) % definite integral

clear
syms x
a = sym(1/2)
f = exp(-a * x^2)
int(f, x, -inf, inf)

clear 
syms x y
f = sin(x*y)
int(int(f,x), y)