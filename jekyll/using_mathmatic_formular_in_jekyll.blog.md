---
layout: post
title:  "Using of mathmatic formular"
date:   2014-06-18 00:36:43
tags: jekyll mathmatics latex 
---

This is a inline $$ 5 + 5 $$ formular, and followed by another block formular which must be preceded and appended by an empty line,

$$
\begin{align*}
  & \phi(x,y) = \phi \left(\sum_{i=1}^n x_ie_i, \sum_{j=1}^n y_je_j \right)
  = \sum_{i=1}^n \sum_{j=1}^n x_i y_j \phi(e_i, e_j) = \\
  & (x_1, \ldots, x_n) \left( \begin{array}{ccc}
      \phi(e_1, e_1) & \cdots & \phi(e_1, e_n) \\
      \vdots & \ddots & \vdots \\
      \phi(e_n, e_1) & \cdots & \phi(e_n, e_n)
    \end{array} \right)
  \left( \begin{array}{c}
      y_1 \\
      \vdots \\
      y_n
    \end{array} \right)
\end{align*}
$$

At this position, the block formular ends. 

This one \$$ 5 + 5 $$ is still displayed as block formular although it is written as inline form.

And this one \$\$ 5 + 5 $$ looks like what it is displayed.
