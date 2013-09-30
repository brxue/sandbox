module A; end
module B; include A; end
class  C; include B; end

puts A.ancestors.inspect
puts B.ancestors.inspect
puts C.ancestors.inspect

puts C < B
puts B < A
puts C < A
puts C.include? B
puts B.include? A
puts C.include? A
puts A.included_modules.inspect
puts B.included_modules.inspect
puts C.included_modules.inspect

puts Fixnum < Integer
puts Integer < Comparable

puts String < Numeric
puts String.ancestors.inspect

__END__


[A]
[B, A]
[C, B, A, Object, Kernel, BasicObject]
true
true
true
true
true
true
[]
[A]
[B, A, Kernel]
true
true

[String, Comparable, Object, Kernel, BasicObject]
