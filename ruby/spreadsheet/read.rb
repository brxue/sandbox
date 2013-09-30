require 'spreadsheet'

book = Spreadsheet.open "book.xls"
sheet1 = book.worksheet 0
sheet2 = book.worksheet 1

book.worksheets.each_with_index do |sheet, i|
	puts "Processing sheet#{i} which named as \"#{sheet.name}\""
	sheet.each_with_index do |row, j|
		puts [row[0], row[1], row[2], row[3]].inspect
	end
end
