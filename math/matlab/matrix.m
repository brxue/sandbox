% vector
a = [1,2,3,4]
a = [1 2 3 4] % ',' is optional
b = 0:10:100 % row vector (start:step:end)

% matrix
a = [1,2,3; 4,5,6; 7,8,9]

% using functions to create matrix
a = rand(3,3) % 3x3 matrix with random elements
a = zeros(3,3) % 3x3 matrix with zero elements
a = ones(3,3) % 3x3 matrix with each element set to 1
a = magic(3) % 3x3magic matrix

% matrix operations
a = a + 10 % 10 is added to each element of a
a = sin(a) % element-wise sin() operation
a = a' % transpose a matrix
a = a * a % matrix multiplication
a = a .* a % element-wise multiplication
a = a^3 % equavalant to a*a*a
a = a .^ 3 % raise each element of a to the 3rd power

% concatenation
a = [1,2,3; 4,5,6; 7,8,9]
A = [a, a] % horizontal concatenation
A = [a; a] % vertical concatenation

% indexing
a = magic(3)
a(3, 2) % row index 3, clolum index 2 (counting from 1)
a(8) % use a single subscript that traverses down each column in order
% a(4,4) % error: out of bound
a(4,4) = 42 % OK, the size of the array increases to accommodate the new comers
a(1:2, 3) % indexing sub-vertical-vectors
a(3, 2:3) % indexing sub-horizontal-vectors
a(3, :) % indexing the 3rd row

