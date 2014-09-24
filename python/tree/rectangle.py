import random

class Rectangle:
    def __init__ (self, width, height, parent = None):
        self.width = width
        self.height = height
        self.parent = parent
        self.children = []

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
            self.children = [Rectangle (width, self.height, self), Rectangle (self.width - width, self.height, self)]
        else:
            height = int (ratio * self.height)
            self.children = [Rectangle (self.width, height, self), Rectangle (self.width, self.height - height, self)]

    def splitUntilLevel (self, maxLevel):
        if maxLevel <= self.level: return
        self.split ()
        for child in self.children: 
			child.splitUntilLevel (maxLevel)

    def __str__ (self):
        s = '{}{} x {}\n'.format (' ' * (2 * self.level), self.width, self.height)
        for child in self.children: s += str (child)
        return s

r = Rectangle (100, 100)
r.splitUntilLevel (3)
print (r)
