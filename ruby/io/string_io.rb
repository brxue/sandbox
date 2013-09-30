require "stringio"

s = StringIO.open("Hello World");
while !s.eof?
	print s.getc
end
puts ""

buffer = ""
StringIO.open(buffer, "w") do |f|
	f.puts "Hi There"
end
puts buffer
