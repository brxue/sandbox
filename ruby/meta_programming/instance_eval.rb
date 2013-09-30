class C
	def initialize x
		@x =x
	end
	attr_accessor :x
end

c = C.new 2

# evaluate a string: define a singleton method on c
puts c.instance_eval "@x = @x + 1; @x"
c.instance_eval "def hello_string; puts self; %Q|Hello String, @x = #@x|; end" # note that #@x is evaluated to nil because "main" hasn't this variable
puts c.singleton_methods.include? :hello_string
puts c.methods.include? :hello_string
puts C.instance_methods.include? :hello_string
puts c.hello_string

puts "++++++++++++++++++++++++++++++++++++++"

# evaluate a block: define a singleton method on c
puts c.instance_eval { @x = @x + 1; @x}
c.instance_eval do def hello_block; "Hello Block, @x = #@x"; end end
puts c.singleton_methods.include? :hello_block
puts c.methods.include? :hello_block
puts C.instance_methods.include? :hello_block
puts c.hello_block

c.instance_eval do
	alias hello hello_block
end
puts c.hello

puts "++++++++++++++++++++++++++++++++++++++"

# define a singleton method on String, that is to define a class method on String
String.instance_eval do 
	def hello
		"Hello World"
	end
end
puts String.hello
puts String.singleton_methods.include? :hello
puts String.methods.include? :hello
puts String.instance_methods.include? :hello

String.instance_eval do
	alias hi hello
end
puts String.hi

puts Object.private_instance_methods.include? :alias
