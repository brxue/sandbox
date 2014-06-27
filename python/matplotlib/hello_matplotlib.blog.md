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
