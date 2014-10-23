def x_neighbor_iterator(size):
    x = -1
    for y in reversed(range(-1, size*2, 1)):
        yield (x, y)

def y_neighbor_iterator(size):
    y = -1
    for x in range(0, size*2, 1):
        yield (x, y)

def xy_neighbor_iterator(size):
    #x = -1
    #for y in reversed(range(-1, size*2, 1)):
    #    yield (x, y)

    #y = -1
    #for x in range(0, size*2, 1):
    #    yield (x, y)

    for (x, y) in x_neighbor_iterator(size):
        yield (x, y)

    for (x, y) in y_neighbor_iterator(size):
        yield (x, y)

for (x, y) in xy_neighbor_iterator(4):
    print x, y
