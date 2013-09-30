class C
	def initialize x
		@x=x
	end
end

class D < C
	def initialize x,y
		super(x)
		@y=y
	end
	
	def dump
		"(#@x, #@y)"
	end
end

d = D.new 1,2
puts d.dump
