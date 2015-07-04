require 'sshkit'
require 'sshkit/dsl'

on 'brxue@120.26.111.214' do |host|
  f = 'tmpfile'
  execute :touch, f
  #info "Please look below:"
  puts capture("ls", "-la", "tmp*")
end
