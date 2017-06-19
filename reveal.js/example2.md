有两种方法可以创建一个由git进行版本管理的`本地`仓库。一种是把当前已经存在的项目目录创建为git仓库；一种是把`远端`已经存在（即已经使用git进行版本管理）的仓库克隆到本地。

---

# 把当前目录初始化为git仓库

假设你在本地有一个目录`./project`，欲把该目录下的所有文件及子目录加入git版本管理，只需该目录下执行`git init`，该命令会在当前目录下生成一个隐身的`.git`目录用于存储所有文件的版本信息，也即`.git`包含了该仓库的所有信息。此时，`./project`目录下的文件尚未加入git管理，你需要通过`git add`命令告诉git，你想对哪些文件进行版本管理，
```bash
git add *.c
git add README
```
此命令告诉git，所有以`.c`为后缀的文件和名为README的文件须加入git，执行`git add`后这些改动（每个文件的所有内容都有改动，因为git认为新加入的文件初始状态为空）将被存入暂存区（`staging area`），然后还需执行`git commit -m "Initial version"`提交暂存区的改动到仓库。

---

# 克隆一个已经存在的git仓库

如果你想克隆（clone）一个已经存在的仓库，比如Ruby的官方仓库[https://github.com/ruby/ruby.git](https://github.com/ruby/ruby.git)，只需执行如下的命令，

```bash
git clone https://github.com/ruby/ruby.git
```

对私有仓库，需要给定用户名和密码，

```bash
git clone username@host:/path/to/repository
```

请注意这里用的是`clone`，实际上就是复制，复制到本地的仓库含有所有本见的版本信息，自此而后你不需要和远端仓库有任何交互即可在本地使用`git`对该仓库进行二次开发，直到有一天你想和远端进行同步（使用`git fetch`取得远端改动，然后使用`git merge`进行合并）或者推送你本地改动到远端（使用`git push`）。

> 除`https`，git还支持`git`，`ssh`，`http`等协议。

当然，你也可以克隆一个本地仓库，

```bash
git clone /path/to/local/repository
```
