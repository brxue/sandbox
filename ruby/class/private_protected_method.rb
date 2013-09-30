class H
	def h1; puts "H1" end
	def h2; end
	def h3; end
	def h4; end

	private :h1, :h2
	protected :h3 # protected methods can only be called on object of current class or subclass
	public :h4 # this is redundant, user-defined methods by default are public
end

h = H.new
#h.h1 # NoMethodError raised

# alternative ways to call private methods
h.send :h1
h.instance_eval {h1}
