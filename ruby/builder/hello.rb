require 'builder'

xml = Builder::XmlMarkup.new

text = xml.person do |p|
  p.name("BrianXue");
  p.phone("123456678");
end

puts text
puts "-------------"

xml = Builder::XmlMarkup.new(:target=>STDOUT, :indent=>4)

xml.instruct! :xml, :version=>"1.0", :encoding=>"UTF-8"
text = xml.person do |p|
  p.comment! "This is a comment."
  p.name("BrianXue");
  p.phone("123456678");
end

params = {xml: {FromUserName: "BrianXue", ToUserName: "Zhangdan"}}
hash = {
  xml: {
    ToUserName: "<![CDATA[#{params[:xml][:FromUserName]}]]>",
    FromUserName: "<![CDATA[#{params[:xml][:ToUserName]}]]>",
    CreateTime: Time.now.to_i,
    MsgType: "<![CDATA[text]]>",
    Content: "<![CDATA[You said: #{params[:xml][:Content]}]]>",
    FuncFlag: 0
  }
}

puts hash.to_xml
