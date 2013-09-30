class C
	def initialize x
		@x = x
	end
end
c = C.new 2

# define an insstance method of C
# note that self in the string is evaluated to main
C.class_eval %Q|def hello_string; puts self; "Hello String, self = #{self}"; end|
puts c.hello_string
puts c.methods.include? :hello_string
puts C.instance_methods.include? :hello_string
puts c.singleton_methods.include? :hello_string

# define an instance method of C
C.class_eval do def hello_block; "Hello Block, self = #{self}"; end end
puts c.hello_block
puts c.methods.include? :hello_block
puts C.instance_methods.include? :hello_block
puts c.singleton_methods.include? :hello_block


# define an instance method of C
C.class_eval do 
	define_method :hello_define_method do
		"Hello define_method, self = #{self}"; 
	end 
end
puts c.hello_define_method
puts c.methods.include? :hello_define_method
puts C.instance_methods.include? :hello_define_method
puts c.singleton_methods.include? :hello_define_method
