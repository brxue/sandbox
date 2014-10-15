import matplotlib.pyplot as plt
import numpy as np

t = np.arange(1, 5)
plt.figure(1) # create the first figure, actually we don't need this, matplotlib will automatically create the first figure for us.
plt.subplot(221)
plt.plot(t, t)
plt.subplot(222)
plt.plot(t, t**2)

plt.figure(2) # create the second figure
plt.plot(t, t**3)

plt.figure(1) # switch to figure 1 as current figure
plt.subplot(223)
plt.plot(t, t**4)

plt.show() # show all the figures
