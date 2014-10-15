import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0, 2*np.pi, 0.01)
plt.plot(x, np.sin(x)) # create a plot instance
plt.show() # show the current figure
