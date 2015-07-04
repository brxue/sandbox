require 'sshkit'
require 'sshkit/dsl'

on 'brxue@120.26.111.214' do |host|
  puts 'Downloading boot log file'
  download! "/var/log/boot.log", "boot.log"
end
