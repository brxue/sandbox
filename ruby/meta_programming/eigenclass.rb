class Object
	def eigenclass
		class << self; self; end
	end
end

class C
end

c = C.new
puts c.eigenclass # eigenclass belongs to an object
puts c.eigenclass == class<<c; self; end

__END__


#<Class:#<C:0x201a3e50>>
true
