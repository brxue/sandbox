# Generators are regular functions except that they use 'yield' instead of 'return' when they want to return data
def hello(arg):
    for i in range(0,10,2):
        yield (i, arg)

# Function call hello() creates an iterator object
# Each time next() is called on the iterator object, the generator resumes where it left-off, it remembers all the local variables and the execution state.
for (i,j) in hello(5):
    print i, j
