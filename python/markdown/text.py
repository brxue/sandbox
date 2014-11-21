import codecs, markdown

# convert 'utf-8' encoding to unicode
input_file = codecs.open("test.md", mode='r', encoding="utf-8")
text = input_file.read()
html = markdown.markdown(text) # markdown only supports unicode as input, the output is also unicode

# convert from unicode to 'utf-8'
output_file = codecs.open("test.html", "w", encoding="utf-8", errors="xmlcharrefreplace")
output_file.write(html)
