puts File.class
puts File.ancestors.inspect

File.delete("test.txt") if File.exist? ("test.txt")

begin
File.open("xuebo")
rescue
puts %Q|File "xuebo" not existed.|
end

fw = File.open("test.txt", "w")
fw.puts "Hello World"
fw.puts "HI"
fw.close

fw = File.open("test.txt", "r")
puts fw.read
fw.close

=begin
"r"  Open for reading. This is the default mode
"r+" Open for reading and writing. Start at beginning of file. Fail if file does not exist.
"w"  Open for writing
"w+" Like "w", but allows reading of the file as well.
"a"  Open for writing, but append to the end of the file if it already exists.
"a+" Like "a", but allows reads also.
=end

File.open("test.txt") do |f|
	puts "Output from File.open"
	puts f.read
end # file automatically closed

puts "+++++++++++++++++++Start testing open++++++++++++++++"

# The Kernel method open works like File.open
open("test.txt", "w") do |f|
	f.puts "Ni hao"
end

open("test.txt") do |f|
	puts "Output from open"
	puts f.read
end

File.delete "test.txt"

# If the file name begins with |, it is treated as on OS command, 
# and the returned stream is used for reading from and writing to that command process.
open("|ls -l") do |f|
	puts f.read
end



