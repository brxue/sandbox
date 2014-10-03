# Setup Git

Before using git, you must firstly let it know who you are and your contact.

```
git config --global user.name "brxue"  
git config --global user.email "brxue@outlook.com"
git config --global core.editor "/usr/bin/vim"
```

These settings will be saved to ~/.gitconfig.

# Create a Project managed by Git

Change to your project directory, run

git init # will create a hidden directory .git

Then add the files you want to be version controlled (of course, there will be some file you don't want to be version controlled, like auto-generated binary files.),

git add test.c
git add include/test.h

Then commit your changes to Git repository (which is your current project directory, remember that Git is a distributed version control system.) with a message (comment).

git commit -m "Initial commit"

# Finding Help 

As for now, we already know some git commands. If you want to know more details, just execute,

git help config
git help init
git help add

# Checking Status

Using `git status` to check the current status of the repository, it will tell you
- Which files was changed, but not staged.
- Which files was newly added, but not under track by Git.

# Staging Changes

Whenever you edited a file, `git add` must be used to stage the changes,

git add hello.c
git add */*.c
git add *

Remember that you can use `git status` to check the status of repository before and after `git add`.

# Unstaging Changes

Sometimes you may want to discard the staged changes, run command

git reset HEAD test.c

Usually `git status` will give this method as a hint.

# Review Difference

    git diff
    git diff --cached
    git diff HEAD

# Commit to Repository

After review the changes by `git diff`, it's the time to commit them to repository,

    git commit  # interactively commit
    git commit -m "Initial submit" # commit with a inline message

7. Checking Out from Repository
8. Showing Log
    git log
    git log -n 10
    git log hello.c
9. Moving File
    git mv hello.c hi.c
10. Remove File
    git rm hello.c
6. Managing Branch
7. 
    
