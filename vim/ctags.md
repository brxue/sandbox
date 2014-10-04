# Install

Before using ctags, it must be installed to your system.

# Generating Tags File

```
ctags --languages=c,c++ -R *  # recursively find all the c/c++ source files under the current directory, and generating a file named `tags` 
```

# Using with Vim

1. `:set tags=/home/brxue/tags` tells Vim where you tags file exist
2. `tag /^hello_*` would find all tags that start with `hello`
3. `Ctrl-]` jumps to the tag underneath the cursor
4. `:ts` or `tselect` shows the list of the previous tag
5. `:tn` or `tnext` goes to the next tag in the list
6. `:tp` or `tprev` goes to the previous tag in the list
7. `:tf` or `tfirst` goes to the first tag of the list
8. `:tl` or `tlast` goes to the last tag of the list
9. `:tags` will show the tags you have traversed sine you opened Vim
10. `Ctrl-t` jumps back up in the stack
