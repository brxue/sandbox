class Point

	def initialize (x, y) 
		@x,@y = x,y
	end
	
	attr_accessor :x, :y
end

class Point
	def +(other)
		# type checking
		raise TypeError, "Point expected" unless other.is_a? Point
		Point.new(@x+other.x, @y+other.y)
	end

	def -(other)
		# another kind of type checking
		raise TypeError, "Point-like argument expected" unless \
			other.respond_to? :x and other.respond_to? :y
		Point.new(@x-other.x, @y-other.y)
	end

	def *(other)
		# yet another kind of type checking
		Point.new(@x * other.x, @y * other.y)
	rescue # if anything goes wrong above
		raise TypeError, "not a Point-like argument encounted"
	end

	def to_s
		"(#@x,#@y)"
	end
end

p1=Point.new(3,4)
p2=Point.new(5,6)
p3=p1-p2
puts p3 # to_s gets called

