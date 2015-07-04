require 'sshkit'
require 'sshkit/dsl'

on 'brxue@120.26.111.214' do |host|
  result = execute('ls', "-la", "/usr/bin/k*")
  puts result
end
