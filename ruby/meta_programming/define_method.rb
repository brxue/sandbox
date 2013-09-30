class Object
	def create_method name, &block
		self.class.send :define_method, name, &block
	end
end

class C
	define_method :hello do |x|
		puts self
		puts x
	end
end

c =C.new
c.hello "Hello World"

c.create_method :hi do |text|
	puts self
	puts text
end
c.hi "Hi"


