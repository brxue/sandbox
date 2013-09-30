syms x
f = sin(x)
t = taylor(f, 'Order', 8, 'ExpansionPoint', 0)
for n=0:1:8 
    t = taylor(f, 'Order', n, 'ExpansionPoint', 0)
    hold on
    ezplot(t, [0, pi]);
end