require 'spreadsheet'

book = Spreadsheet::Workbook.new

sheet1 = book.create_worksheet :name=>"sheet1"

6.times do |i|
	4.times do |j| 
		sheet1[i,j] = i+j
	end
end

sheet1

# set format of row 0
sheet1.row(0).default_format = Spreadsheet::Format.new :color=>:blue, :weight=>:bold, :size=>18

# set back ground of row 1
yellow_background = Spreadsheet::Format.new :pattern_fg_color=>:yellow, :pattern=>1
sheet1.row(1).default_format = yellow_background

# set border style of row 2
border = Spreadsheet::Format.new :right=>:thick, :bottom=>:thin
4.times do |i| 
	sheet1.row(2).set_format(i, border) 
end

# set height of row 3
sheet1.row(3).height = 30

# set background of cell 1 of row 4
cell41 = Spreadsheet::Format.new :pattern_fg_color=>:red, :pattern=>1
sheet1.row(4).set_format(1,cell41)

# merge 
start_row = 5
start_col = 0
end_row = 5
end_col = 1
sheet1.merge_cells(start_row, start_col, end_row, end_col)

book.write "formated_book.xls"

