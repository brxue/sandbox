syms t w

f = t^4
laplace(f)

f = sin(w*t)
laplace(f)

clear

syms s
f = 1/s^2
ilaplace(f)

