class Vector
	attr_accessor :x, :y

	def initialize x, y
		@x,@y=x,y
	end
	
	# Immutable method
	def add(other)
		Vector.new(@x+other.x, @y+other.y)
	end

	# Mutable method
	def add!(other)
		@x += other.x
		@y += other.y
		self
	end
end

v1 = Vector.new(2,3)
v2 = Vector.new(4,5)

puts v1
puts v1.add(v2)
puts v1.add!(v2)

puts v1.object_id == v1.add!(v2).object_id
