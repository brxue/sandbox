class B; end

c = class C < B; 
		def hello
			"Hello World"
		end

		self; 
	end.new

puts c.class
puts C.superclass
puts c.instance_of? C
puts c.is_a? C
puts c.is_a? B
puts c.kind_of? C
puts c.respond_to? :hello

__END__

C
B
true
true
true
true
true
