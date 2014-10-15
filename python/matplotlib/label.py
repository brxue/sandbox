import matplotlib.pyplot as plt
import numpy as np

f = plt.figure()
ax = plt.subplot(111)
ax.set_xticklabels(list('ABCD'))
ax.set_yticklabels(list('IJKL'))
ax.set_xticks([1.0, 1.5, 2.5, 3.5])
ax.set_xticks(np.array([1.0, 1.5, 2.0, 2.5]))
ax.set_yticks(np.array([1.0, 1.5, 2.0, 2.5]) * 2)
plt.plot([1,2,3])
plt.show()
