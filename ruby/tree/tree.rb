=begin
                +------------+
                |    ROOT    |
                +-----+------+
        +-------------+------------+
        |                          |
+-------+-------+          +-------+-------+
|  CHILD 1      |          |  CHILD 2      |
+-------+-------+          +---------------+
        |
        |
+-------+-------+
| GRANDCHILD 1  |
+---------------+
=end

require 'tree'

# ..... Create the root node first.  Note that every node has a name and an optional content payload.
root_node = Tree::TreeNode.new("ROOT", "Root Content")

# ..... Now insert the child nodes.  Note that you can "chain" the child insertions for a given path to any depth.
root_node << Tree::TreeNode.new("CHILD1", "Child1 Content") << Tree::TreeNode.new("GRANDCHILD1", "GrandChild1 Content")
root_node << Tree::TreeNode.new("CHILD2", "Child2 Content")

# ..... Lets print the representation to stdout.  This is primarily used for debugging purposes.
root_node.print_tree

# ..... Lets directly access children and grandchildren of the root.  The can be "chained" for a given path to any depth.
child1 = root_node["CHILD1"]
grand_child1 = root_node["CHILD1"]["GRANDCHILD1"]

# ..... Lets retrieve siblings of the current node as an array.
siblings_of_child1 = child1.siblings

# ..... Lets retrieve immediate children of the root node as an array.
children_of_root = root_node.children

# ..... This is a depth-first and L-to-R pre-ordered traversal.
root_node.each { |node| node.content.reverse }

# ..... Lets remove a child node from the root node.
root_node.remove!(child1)

