BLOG_REPOSITORY = "brxue.github.com"
BLOG_ROOT = "../#{BLOG_REPOSITORY}"
BLOG_POSTS = "#{BLOG_ROOT}/_posts"
BLOG_DOWNLOADS = "#{BLOG_ROOT}/downloads"

task :default => :pub

def get_file_timestamp(f)
	File.mtime(f).to_s.split(' ')[0]
end

posts = Dir.glob("**/*.blog.md") 
task :pub => posts do
	puts "Publish to #{BLOG_REPOSITORY}"
	posts.each do |post|
		post_name = get_file_timestamp(post) + "-" + File.basename(post, ".blog.md").gsub("_", "-") + ".md"
		post_name = BLOG_POSTS + "/" + post_name
		sh "cp #{post} #{post_name}"
	end
end
