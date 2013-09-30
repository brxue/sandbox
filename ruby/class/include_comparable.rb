class Circle
	def initialize r
		@r = r
	end
	
	def area
		3.14 * @r * @r
	end

	# mixin methods from the comparable module
	include Comparable
	
	# define an ordering for points based on their distance from the origin
	# define one method, and get many other methods from Comparable
	def <=>(other)
		area <=> other.area
	end
end

c0 = Circle.new(1)
c1 = Circle.new(2)
puts c0==c1
puts c0<c1
puts c0>c1
