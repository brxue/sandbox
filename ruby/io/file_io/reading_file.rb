File.delete("test.txt") if File.exist? ("test.txt")

File.open("test.txt", "w") do |f|
	f << "Hello World\n" 
	f << "Hi There\n"
	f << "Ni Hao\n"
	f << "Chi le mei\n"
end

# Read entire file to a string
File.open("test.txt") do |f|
	temp = f.read
	puts temp.class
	puts temp
end
puts ""

# Read entire file to an array
File.open("test.txt") do |f|
	temp = f.readlines
	puts temp.class
	temp.each do |l|
		puts l
	end
end
puts ""

# Another way to read entire file to an array
puts File.readlines("test.txt")

File.delete "test.txt"
