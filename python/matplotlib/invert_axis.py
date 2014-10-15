import matplotlib.pyplot as plt
import numpy as np

plt.subplot(111)
plt.plot([0,1,2])
plt.axis([0, 2, 0, 2])
plt.gca().invert_yaxis() # inverted Y axis, will increase to bottom instead of top
plt.show()
