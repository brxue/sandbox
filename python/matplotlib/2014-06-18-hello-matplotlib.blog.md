---
layout: post
title:  "Hello matplotlib"
date: 2014-06-18 22:59:26
tags: python, matplotlib
downloads: /downloads/2014-06-18-hello-matplotlib
---

The following Python code,

{% highlight python %}
from pylab import *

t = arange(0.0, 2.0, 0.01)
s = sin(2*pi*t)
plot(t, s)

xlabel('time (s)')
ylabel('voltage (mV)')
title('About as simple as it gets, folks')
grid(True)
savefig("sine.png")
show()
{% endhighlight %}

will plot out the following image,

![RGB]({{ page.downloads }}/sine.png).
