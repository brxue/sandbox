# Setup Git

Before using git, you must firstly let it know who you are and your contact.

```
git config --global user.name "brxue"  
git config --global user.email "brxue@outlook.com"
git config --global core.editor "/usr/bin/vim"
git config --global color.diff always # colored `git diff` result
git config --global color.ui always # colored `git` std output
git config --global push.default simple # only matched branch will be pushed
git config --global credential.helper cache # set git to use the crendential memory cache
git config --global credential.helper 'cache --timeout==28800' set the cache to timeout after 8 hour
```

These settings will be saved to ~/.gitconfig.

# Create a Project managed by Git

Change to your project directory, run

```
git init # will create a hidden directory .git
```

Then add the files you want to be version controlled (of course, there will be some file you don't want to be version controlled, like auto-generated binary files.),

```
git add test.c
git add include/test.h
```

Then commit your changes to Git repository (which is your current project directory, remember that Git is a distributed version control system.) with a message (comment).

```
git commit -m "Initial commit"
```

# Finding Help 

As for now, we already know some git commands. If you want to know more details, just execute,

```
git help config
git help init
git help add
```

# Checking Status

Using `git status` to check the current status of the repository, it will tell you
- Which files was changed, but not staged.
- Which files was newly added, but not under track by Git.

# Staging Changes

Whenever you edited a file, `git add` must be used to stage the changes,

```
git add hello.c
git add */*.c
git add *
```

Changes must be re-stageed if new edits are made after `git add`. Remember that you can use `git status` to check the status of repository before and after `git add`.

# Unstaging Changes

Sometimes you may want to discard the staged changes, run command

```
git reset HEAD test.c
```

Usually `git status` will give this method as a hint.

# Review Difference

```
git diff
git diff --cached
git diff HEAD
```

# Commit to Repository

After review the changes by `git diff`, it's the time to commit them to repository,

```
git commit  # interactively commit
git commit -m "Initial submit" # commit with a inline message
```

# Review History

```
git log # checking overall log of repository
git log --pretty=oneline # try it by yourself
git log test.c # checking file history
```

# Getting Older Versions

1. Getting an older file

```
git log test.c # firstly check file history, get the hash ID
git checkout <hash-id> -- test.c # checkout the older file
```

2. Getting an older tree

```
git log 
git checkout  <hash-id>
```

3. Return to the latest version in the master branch

```
git checkout master
```

# Tagging Versions

```
git tag beta-v0.1 # Tagging the current tree status as beta-v0.1
git checkout beta-v0.1 # checkout by tag name
git tag # Viewing what tags are available
git log -all # Adding `-all` option to see tags in the history
git tag -d beta-v0.1 # Remove a tag
```

# Undoing Local Changes before Staging

Suppose file test.c had been edited but not staged, use `git checkout -- test.c` to get the repository's version.

# Undoing Staged Changes before Commiting

Suppose file test.c had ben edited and staged by `git add`, but still not commited to the repository, 

```
git reset HEAD test.c # firstly resets the staging area to be whatever is in HEAD, the working tree will still has the unwanted changes.
git checkout -- test.c # checkout the repository's version
```

# Undong Commited Changes


# Moving and Removing File

```
    git mv hello.c hi.c
    git rm hello.c
```

