require 'rest-client'

response = RestClient.get('http://www.baidu.com')

puts response
