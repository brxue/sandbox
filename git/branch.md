# List Branches

```
git branch # list all of the branches in your repository
```

# Create a Branch

1. Two step method

```
git branch <branchname> # create a branch
git checkout <branchname> # switch to the new branch
```

2. Short cut method

```
git checkout -b <branchname>
```

# Delete a Branch

```
git branch -d <branchname> # delete the specified branch
```

# Switch to Another Brnach

```
git checkout <branchname>
git checkout master # switch to master branch
```

# Merging another Branch to the current Branch

```
git checkout hello # switch to branch hello
git merge master # merge master branch to hello, it will report conflicts if any
# Suppose there is conflict in file test.c, then open it in your editor and fix them
git add test.c # Re-add test.c after resolving
git commit # Commit it
git log -all # checking history
```

