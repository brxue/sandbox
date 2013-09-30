x = 1
eval "x= x+1;"
puts x

class C
	def initialize x
		@x = x
	end
	attr_accessor :x
	def get_binding
		binding
	end
end

c = C.new 5
eval("@x = 6", c.get_binding)
puts c.x


