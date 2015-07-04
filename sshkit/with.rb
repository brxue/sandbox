require 'sshkit'
require 'sshkit/dsl'

on 'brxue@120.26.111.214' do |host|
  with 'TEST_ENV'=>"\"Hello World!\"" do
    puts capture("env").include?('TEST_ENV')
  end
end
