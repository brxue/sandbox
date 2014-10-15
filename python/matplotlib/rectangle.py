import random
import matplotlib.pyplot as plt
import numpy as np

class Tree:
    def __init__ (self, width, height, parent = None):
        self.width = width
        self.height = height
        self.parent = parent
        self.children = []

        self.x = 0
        self.y = 0

    @property
    def level (self):
        return 0 if not self.parent else 1 + self.parent.level
	
	# Divide the current rectangle into two parts
    def split (self):
        if self.children: raise Exception ('Already split')
        ratio = random.random () * .5 + .25 #split between 1/4 and 3/4

		# Divide the boundary longer than the other
        if self.width > self.height:
            width = int (ratio * self.width)
            self.children = [Tree (width, self.height, self), Tree (self.width - width, self.height, self)]

            self.children[0].x = self.x
            self.children[0].y = self.y
            self.children[1].x = self.x + width
            self.children[1].y = self.y

            self.children[0].ax = self.ax
            self.children[1].ax = self.ax
        else:
            height = int (ratio * self.height)
            self.children = [Tree (self.width, height, self), Tree (self.width, self.height - height, self)]

            self.children[0].x = self.x
            self.children[0].y = self.y
            self.children[1].x = self.x
            self.children[1].y = self.y + height

            self.children[0].ax = self.ax
            self.children[1].ax = self.ax

    def splitUntilLevel (self, maxLevel):
        if maxLevel <= self.level: return
        self.split ()
        for child in self.children: 
			child.splitUntilLevel (maxLevel)

    def __str__ (self):
        s = '{}{} x {}\n'.format (' ' * (2 * self.level), self.width, self.height)
        for child in self.children: s += str (child)
        return s

    def draw(self):
        rect = plt.Rectangle((self.x, self.y), self.width, self.height, edgecolor='black', facecolor='white')
        self.ax.add_patch(rect)
        for node in self.children:
            node.draw()

ax = plt.subplot(111, aspect='equal')
ax.set_xticks([]) # no X ticks
ax.set_yticks([]) # no Y ticks
ax.xaxis.tick_top()
plt.gca().invert_yaxis()

r = Tree (100, 100)
r.ax = ax

r.splitUntilLevel (3)
print (r)

r.draw()

plt.axis([0, 100, 0, 100])
plt.show()
