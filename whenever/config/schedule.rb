set :output, "/home/brxue/whenever.log"

every 1.minutes do
  command "echo hello world"
end

