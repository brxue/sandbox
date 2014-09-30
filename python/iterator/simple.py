a = [i*i for i in range(10)]

# Get an interator object which contains a next() method
itr = iter(a)

for i in range(10):
    print itr.next()
