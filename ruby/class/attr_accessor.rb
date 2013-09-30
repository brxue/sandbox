class Text
	attr_accessor :text # read and write
	attr_reader :rtext  # read only
	attr_writer :wtext  # write only
end
t = Text.new

puts t.instance_variables
t.text = "Instance variables only get created after it is assigned"
puts t.instance_variables

