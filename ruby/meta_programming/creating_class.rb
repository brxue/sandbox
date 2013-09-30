C = Class.new
D = Class.new C
puts D.superclass

M = Module.new
M.class_eval do
	def nihao
		"Nihao @ #{self}"
	end
end

D.class_eval do
	include M
	def hello
		"Hello World"
	end
	define_method :hi do
		"Hi @ #{self}"
	end
end

puts D.included_modules.inspect
puts D.new.hello
puts D.new.hi
puts D.new.nihao



__END__


C
[M, Kernel]
Hello World
Hi @ #<D:0x201a3748>
Nihao @ #<D:0x201a36f8>
