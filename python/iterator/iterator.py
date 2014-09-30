class A:
    def __init__(self):
        self.idx = 0
        self.data = [i*i for i in range(10)]

    # This makes it possible to call iter() function on object of class A
    # Return an object which contains an next() method
    def __iter__(self):
        return self
    
    def next(self):
        if self.idx == 10:
            raise StopIteration
        data = self.data[self.idx]
        self.idx += 1
        return data

# A() creats an iterator object
for i in A():
    print i
