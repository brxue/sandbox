module M
	def hello 
		puts "Hello, #{self}"
	end
end

class C; end
c = C.new

c.extend M
c.hello
puts c.singleton_methods.include? :hello # true
puts c.methods.include? :hello # true
puts C.instance_methods.include? :hello # false


String.extend M
String.hello
puts String.singleton_methods.include? :hello



__END__


Hello, #<C:0x201a3b6c>
true
true
false
Hello, String
true
