SRC_ROOT = "."
DST_ROOT = "../brxue.github.com"

class Post
	attr_accessor :fullname, :name, :dirname
	def initialize(fullname)
		@fullname = fullname
		@name = File.basename(fullname)
		@dirname = File.dirname(fullname)
	end
end

class SrcPost < Post
	attr_reader :basename, :jekyllname
	def initialize(fullname)
		super(fullname)
		@basename = File.basename(fullname, ".blog.md");
		@jekyllname = @basename.gsub("_", "-") + ".md"
	end
	def timestamp
		File.mtime(self.fullname).to_s.split[0]
	end

	class << self
		def all
			Dir.glob("**/*.blog.md").map do |fullname| SrcPost.new(fullname) end
		end
	end
end

class DstPost < Post
	attr_reader :basename, :purename
	def initialize(fullname)
		super(fullname)
		@basename = File.basename(fullname, ".md");
		@purename= @basename.gsub(/\d{4}-\d{2}-\d{2}-/, '') 
		@timestamp = @basename[0,9]
	end
	
	def add_front_matter
		File.open(fullname) do |f|
			puts "---"
			puts "layout: post"
			puts %Q|title: @purename.gsub("-", " ")|
			puts "---"
		end
	end

	class << self
		def all
			@dst_posts = SrcPost.all.map do |post|
				path = DST_ROOT + "/_posts/" + post.timestamp + "-" + post.jekyllname
				DstPost.new(path)
			end
		end

		attr_reader :actual_dst_posts
		def actual_all
			@actual_dst_posts =Dir.glob("#{DST_ROOT}/_posts/*.md").map do |fullname| 
				DstPost.new(fullname) 
			end
		end
		def clean
			return if (@dst_posts.size == @actual_dst_posts.size) 
			@dst_posts.each do |key|
				result = [];
				@actual_dst_posts.each do |post|
					if (post.purename == key.purename)
						result << post 
					end
				end
				if result.size > 1
					0.upto(result.size - 2) do |i|
						puts "rm #{result[i].fullname}"
						system "rm #{result[i].fullname}"
					end
				end
			end
		end
	end
end

src_posts = SrcPost.all
dst_posts = DstPost.all
actual_dst_posts = DstPost.actual_all

task :default => :clean_dst_redundancy
task :clean_dst_redundancy => :pub do
	DstPost.clean
end
task :pub => dst_posts.map {|post| post.fullname}

dst_posts.each_with_index do |dpost, i|
	spost = src_posts[i]
	file dpost.fullname => spost.fullname do
		sh "cp #{spost.fullname} #{dpost.fullname}"
		#dpost.add_front_matter
	end
end

task :ls_src_posts do
	puts src_posts.map {|post| post.fullname}
end

task :ls_dst_posts do
	puts dst_posts.map {|post| post.fullname}
end

task :ls_actual_dst_posts do
	puts actual_dst_posts.map {|post| post.fullname}
end
