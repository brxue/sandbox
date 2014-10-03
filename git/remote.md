# Cloning Existed Repositories

It is easy to clone an existed repository, the cloned one will contain almost all the information in the original repository. `git remote show` command can be used to show detailed information about the remote repository.

```
git clone codebox cloned_codebox # clone a new repository from your existed repository
git clone https://github.com/strukturag/libde265 # clone a remote repository
```

By default, all the cloned repository will name their remote repository as `origin`.

Typically, remote repositories live on a separate machine, possibly a centralized server. HOwwever, it is also possible to point to repository on the same machine. It is a strong convention to use the name "origin" for the primary centralized remote repository if there is one.

# List Remote Connections

```
git remote # show the name of the remote repository
git remote -v # show detaild information
git remote show origin # show the detailed info about the remote repository named `origin`
```

# Add and Remove Remote Connections

```
git remote add <name> <url> # Create a new connection to a remote repository in <url> ,name it as <name>
git remote rm <name> # Remove a remote connection
git remote rename <old-name> <new-name> # Rename a remote connection
```

# List Remote Branches

```
git branch # will only list the branches in the local repository
git branch -a # will list all the branches both in local and remote
git branch -r # will only list remote branches
```

# Getting Remote Changes

1. Two-step method

```
git fetch <remote-name> # will pull latest changes from a remote repository, by default, it is `origin`; but before merging, the changes is not really reflected to local files, it is in orign/master branch. `<remote-name>` is by default `origin`.
git fetch <remote-name> <branch-name> # same as above, but only fetch `<branch-name>` brach, by default, it is `master`.
git log --oneline master...origin/master # see what commit had been added to remote master branch since last fetch.
git merge origin/master # merge `master` branch of remote repository `origin` to current local branch.
```

2. Single command

```
git pull # is equal to `git fetch` followed by `git merge origin/master`
```

# Pushing Chnages to Remote

```
git push <remote> <branch> # push specified local branch to remote repository
git push <remote> -all # push all local branches
git push <remote> --tags # push all your local tags to remote
```


