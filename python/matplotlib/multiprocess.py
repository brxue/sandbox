from multiprocessing import Process
from matplotlib.pyplot import plot, show

def plot1():
    plot([1,2,3])
    show()

p1 = Process(target=plot1)
p1.start()

#def plot2():
#    plot([3,2,1])
#    show()
#
#p2 = Process(target=plot2)
#p2.start()

print 'Computation continues...'

p1.join()
#p2.join()

print 'The end.'
