# Cloning Existed Repositories

It is easy to clone an existed repository, the cloned one will contain almost all the information in the original repository. `git remote show` command can be used to show detailed information about the remote repository.

```
git clone codebox cloned_codebox # clone a new repository from your existed repository
git clone https://github.com/strukturag/libde265 # clone a remote repository
git remote # show the name of the remote repository
git remote show origin # show the detailed info about the remote repository named `origin`
```

Typically, remote repositories live on a separate machine, possibly a centralized server. HOwwever, it is also possible to point to repository on the same machine. It is a strong convention to use the name "origin" for the primary centralized remote repository if there is one.

# List Remote Branches

```
git branch # will only list the branches in the local repository
git branch -a # will list all the branches both in local and remote
```

# Getting Remote Changes

1. Two-step method

```
git fetch # will pull latest changes from a remote repository, by default, it is `origin`; but before merging, the changes is not really reflected to local files.
git merge origin/master # merge `master` branch of remote repository `origin` to current local branch.
```

2. Single command

```
git pull # is equal to `git fetch` followed by `git merge origin/master`
```

# Pushing Chnages to Remote


