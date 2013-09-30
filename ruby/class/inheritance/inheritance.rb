# By default, all class inherits Object
class C; end
c = C.new
puts c.class
puts c.class.superclass
puts c.class.ancestors.inspect

# D subclassing C
class D < C; end
d = D.new
puts d.class
puts d.class.superclass
puts d.class.ancestors.inspect
