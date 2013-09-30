[x, y] = meshgrid(-2:0.1:2)
f = x .* exp(-x.^2 - y.^2)
surf(x,y,f)

figure % start a new figure, or else the previous figure will be overriden
mesh(x,y,f) % another way to plot 3D figure