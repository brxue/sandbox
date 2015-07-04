require 'sshkit'
require 'sshkit/dsl'

on 'brxue@120.26.111.214' do |host|
  puts 'Uploading hello.rb in local machine to remote as ~/test/hello.rb'
  upload! "hello.rb", "/home/brxue/test/hello.rb"
  puts capture(:ls, '-l', 'test/hello.rb')
end
