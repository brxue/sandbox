require 'psych'

class ScalarHandler < Psych::Handler
	def start_stream encoding
		puts "STREAM START"
	end

    def end_stream
		puts "STREAM END"
    end

    def start_document version, tag_directives, implicit
		puts "Start Document"
    end

    def end_document implicit
		puts "End Document"
    end

    def start_sequence anchor, tag, implicit, style
		puts "Start Sequence"
    end

    def end_sequence
		puts "End Sequence"
    end

    def start_mapping anchor, tag, implicit, style
		puts "Start Mapping"
    end

    def end_mapping
		puts "End Mapping"
    end

	def scalar value, anchor, tag, plain, quoted, style
		puts "Got scalar (value = #{value})"
	end

    def alias anchor
		puts "Got alias (anchor = #{anchor}"
    end
end

parser = Psych::Parser.new(ScalarHandler.new)
parser.parse(File.open("../test.yml"))
