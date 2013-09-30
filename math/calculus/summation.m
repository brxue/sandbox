syms n
s1 = symsum(1/(n^2), n, 1, inf)

clear
syms x n
s2 = symsum(x^n, n, 0, inf)