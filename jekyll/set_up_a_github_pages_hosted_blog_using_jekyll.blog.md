---
layout: post
title:  Setup a GitHub Pages hosted blog using jekyll
date: 2014-06-18 00:19:26
tags: jekyll
---

1. Create a empty repository on github.com (don't initialize it with README), and the name of this repository must be in the format of "yourusername.github.com".
2. Install jekyll gem to your local computer: 
	* gem install jekyll.
3. Setup an initial jekyll directory structure: 
	* jekyll new yourusername.github.com
4. Initilize this directory: 
	* git init
5. Add all files under yourusername.github.com to stage area: 
	* git add *
6. Submit it: 
	* git commit -m "first commit"
7. Corelate your local directory with GitHub repository: 
	* git remote add origin https://github.com/brxue/brxue.github.com.git
8. Push your local git directory to GitHub: 
	* git push -u origin master
