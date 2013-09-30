syms x
f = abs(x)/x
a = -pi
b = pi
L = (b-a)/2
if (a==-b)
    % symmetrical region
else
    % substitute x with x+L+a to make f symmetrical
    f = subs(f, x, x+L+a);
end

% calculate fourier coefficients
an = [];
bn = [];
for n=1:10
    an(n) = int(f*cos(n*pi*x/L), x, -L, L)/L;
    bn(n) = int(f*sin(n*pi*x/L), x, -L, L)/L;
end

% calculate summation from order 1 to 10
syms fn
a0 = int(f, x, -L, L)/L;
for n=1:10
    fn(n) = a0/2;
    for k=1:n
        fn(n) = fn(n) + an(k)*cos(k*pi*x/L) + bn(k)*sin(k*pi*x/L);
    end
    if (a==-b)
        % symmetrical region
    else
        % reverse substitution
        fn(n) = subs(fn(n), x, x-L-a);
    end    
end

% display the highest order summation
pretty(fn(10))

% plotting
ezplot(f, [-4*pi, 4*pi])
hold on
for n=1:10
    ezplot(fn(n), [-4*pi, 4*pi])
end