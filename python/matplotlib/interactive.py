import time
import matplotlib.pyplot as plt

plt.plot([1,2,3])

print "hello1"
plt.plot([1,4,9])

print "hello2"
plt.plot([1,16,81])

# At the end of the script, call show() to make sure Python doesn't exit before the figure shows
plt.show()
# After show() is called, the user must close it mannualy to continue to the next show

print "hello3"
plt.plot([1,1,1])
plt.show()
