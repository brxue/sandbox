require "open-uri"

open("http://www.google.com.hk") do |f|
	puts f.readlines[0]
end

