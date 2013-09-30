class C
	def hello;
		puts self
	end
end

class D < C
	# overrid the method hello defined in superclass
	def hello;
		puts self
	end
end

d = D.new
d.hello
