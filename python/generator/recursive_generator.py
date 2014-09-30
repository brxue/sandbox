# The Wrong Way:
def hello1(n):
    yield n
    n += 1
    hello1(n)

print "hello1:"
k = 0
for i in hello1(3):
    if k == 10:
        break
    else:
        print i
    k += 1

#-------------------------------

# The Correct Way:
def hello2(n):
    yield n
    n += 1
    for i in hello2(n): # Note: hello2() is a iterator, it must be iterated and yielded out
        yield i

print "hello2:"
k = 0
for i in hello2(3):
    if k == 10:
        break
    else:
        print i
    k += 1

