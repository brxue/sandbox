def neighbor_iterator(size):
    x = -1
    for y in range(-1, size*2-1, 1):
        yield (x, y)

    y = -1
    for x in range(0, size*2-1, 1):
        yield (x, y)

for (x, y) in neighbor_iterator(4):
    print x, y
