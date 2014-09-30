class B:
    def __init__(self):
        self.idx = 0
        self.data = [i*i for i in range(10)]

    def next(self):
        if self.idx == 10:
            raise StopIteration
        data = self.data[self.idx]
        self.idx += 1
        return data

class A:
    def __init(self):
        pass

    # Should return an object with method next()
    def __iter__(self):
        return B()

# A() creates an iterator object
for i in A():
    print i
