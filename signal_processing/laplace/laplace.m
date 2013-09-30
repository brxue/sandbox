syms t s
f = sin(2*pi*50*t)
F = laplace(f)

[x,y]=meshgrid(-2*pi:0.1:2*pi, -2*pi:0.1:2*pi);
surf(x, y, abs(subs(F, s, x+i*y)))