require 'spreadsheet'

# ---------------------
# Create a spreadsheet
# ---------------------
book = Spreadsheet::Workbook.new


# ---------------------
# Create 2 worksheets
# ---------------------
sheet1 = book.create_worksheet :name=>'sample sheet1'
sheet2 = book.create_worksheet :name=>'sample sheet2'


# ---------------------
# Write to sheet1
# ---------------------

# write row 0
4.times do |i| 
	sheet1[0,i] = i 
end

# write row 1
sheet1.row(1).concat([1,2,3,4])

# write row 2
4.times do |i| 
	sheet1.row(2).push i+2 
end

# write row 3
sheet1.row(3).replace [3,4,5,6]

# write row 4
row4 = sheet1.row(4); 
4.times do |i| 
	row4[i] = i+4 
end

# write row 5
sheet1.update_row 5, 5, 6
sheet1.row(5)[2] = 7
sheet1.row(5).insert 3, 8

# ---------------------
# Write to sheet1
# ---------------------
sheet2[0,0]=1234

# ---------------------
# Write the spreadsheet to a file named as "book.xls"
# ---------------------
book.write "book.xls"
