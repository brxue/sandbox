import matplotlib.pyplot as plt
import numpy as np

f = plt.figure()
ax = plt.subplot(111)
ax.yaxis.tick_right()
# alternatively ax.yaxis.set_ticks_position('right') # set x ticks at the top instead of bottom
ax.yaxis.set_label_position('right') # also move label to right
plt.ylabel("Y label")
plt.plot([0,1,2])
plt.show()
