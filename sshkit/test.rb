require 'sshkit'
require 'sshkit/dsl'

on 'brxue@120.26.111.214' do |host|
  if test("[ -d /usr/bin ]")
    info "Directory /usr/bin already exists!"
  end
  if not test("[ -d /usr/noway ]")
    info "Opps! Directory not exists."
  end
end
