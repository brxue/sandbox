class C; end
c = C.new

def c.hello
	puts %Q|Hello, I'm a singleton method which only belongs to object "c"|
end

puts c.methods.include? :hello
puts c.singleton_methods.include? :hello
puts C.instance_methods.include? :hello

d = C.new
puts d.methods.include? :hello


# signleton methods exist in eigenclass of the corresponding object
eigenclass = class << c; self; end
puts eigenclass.instance_methods.include? :hello

__END__


true
true
false
false
true
