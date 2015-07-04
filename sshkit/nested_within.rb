require 'sshkit'
require 'sshkit/dsl'

on 'brxue@120.26.111.214' do |host|
  within "/var" do
    puts capture(:pwd)
    within :log do
      puts capture(:pwd)
    end
  end
end
