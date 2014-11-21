import codecs, markdown

# convert 'utf-8' encoding to unicode
input_file = codecs.open("text.md", mode='r', encoding="utf-8")
text = input_file.read()
md = markdown.Markdown(extensions=['toc']) # markdown only supports unicode as input, the output is also unicode
html = md.convert(text)

# convert from unicode to 'utf-8'
output_file = codecs.open("toc.html", "w", encoding="utf-8", errors="xmlcharrefreplace")
output_file.write(md.toc)
