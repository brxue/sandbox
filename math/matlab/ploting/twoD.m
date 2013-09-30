x = -2*pi:0.001:2*pi
y = sin(x)
plot(x, y)
xlabel('X')
ylabel('Y')
title('Plot of the sine function')

hold on % plot y2 on the same figure with y

y2 = cos(x)
plot(x, y2, 'r') % use red line
legend('sin', 'cos')

plot([-3*pi, 3*pi], [0, 0], 'black') % plot x-axis
plot([0, 0], [-1.5, 1.5], 'black') % plot y-axis
