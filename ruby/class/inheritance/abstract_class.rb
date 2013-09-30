class Abstract
	def hello
		text # the text method hasn't been defined yet
	end
end

class Concrete < Abstract
	def text
		puts "Hello World"
	end
end

c = Concrete.new
c.hello
