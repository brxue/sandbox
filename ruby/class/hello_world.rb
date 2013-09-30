# Defining a class named "Hello"
class Hello
	puts "Hello, I'm insiding a class. self = #{self}"

	# constructor, gets called when object created
	def initialize m
		print "Hello, I'm insiding an instance, "
		puts "self = #{self}, self.class = #{self.class}"

		@msg = m # member variable gets created on the first time it is assigned
	end

	# getter
	def msg; @msg; end

	# setter
	def msg=(m); @msg = m; end
end

# Instantiating the Hello class
h = Hello.new "Hello World"
puts "Object #{h} is an instance of class #{h.class}"

# Access member variables
puts h.msg
h.msg = "Hi, there"
puts h.msg

