% dirivative of sin(x) is cos(x)
syms x h
f = (sin(x+h) - sin(x))/h
limit(f, h, 0) % cos(x)

clear
syms x 
f = (1+(1/x))^x
limit(f, x, inf) % e

clear
syms x
f = sin(x)/x
limit(f, x, 0) % 0

clear
syms x
f = x/abs(x)
limit(f, x, 0, 'left') % -1
limit(f, x, 0, 'right') % 1

clear
syms x y
f = sin(x*y)/x
limit(limit(f, x, 0), y, 0) % limit when (x,y)->(0,0)