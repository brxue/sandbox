import matplotlib.pyplot as plt
import numpy as np

ax = plt.subplot(111)
ax.plot([0,1,2])

plt.axis([0, 2, 0, 2])

plt.gca().invert_yaxis() # inverted Y axis, will increase to bottom instead of top
ax.xaxis.set_ticks_position('top') # set x ticks at the top instead of bottom

plt.show()
