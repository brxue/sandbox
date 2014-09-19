给定一个二进制数，0b1101，它表示一个什么样的东西，完全在于使用者的定义。你可以认为它是一个4位的无符号数13；或者，你定义最高位bit3表示符号（1位负，0为正），那么它是-5，这即是所谓的原码表示法；如果你把它解释成一个位宽为4的反码表示，那么它所表示的十进制数是-2；如果解释成补码，那么它是-3.对于你的每一种定义，这4个比特的二进制数总有一个所能表示的数的范围，根据代数学的理论，位宽为N的二进制数最多可以有2^N个不同组合，设N为4，则它可以表示16个不同的数，依次为0000到1111。

对于给定的二进制数，欲知它所表示的十进制数，必须定义位宽N和表示法。以N=4为例。根据原码的定义，最高位是符号位，其它为数值位，它规定0b0000到0b0111这8个组合依次用来表示十进制数0到7,0b1000到0b1111依次表示-0到-7. 对反码，它规定0b0000到0b0111这8个组合依次用来表示十进制数0到7,把0b0000到0b1111中的数按位取反表示相应的负数，比如0b0101表示5，那么0b1010表示-5；对补码，它也规定0b0000到0b0111这8个组合依次用来表示十进制数0到7，所不同的是，它把0b0000到0b1111中的数按位取反再加1表示相应的负数，比如0b0101表示5，那么0b1010+1即1011表示-5。

事实上，反码和补码都基于代数中模的概念而定义，反码的模是(2^N)-1，补码的模是2^N。对反码，给定它能表示的范围内的十进制数3，它以15为模的补数是15-3=12，而12的二进制表示为1100，它正是反码中的-3.对补码，给定十进制数3，它以16为模的补数是16-3=13，而13的二进制表示为1101，它正是补码中的-3.

多数计算机内部采用补码表示数字。以C语言中的char型为例，它有无符号（unsigned char）和符号（char）两种表示形式，此时N=8。为方便起见假设存储器宽度为8，某地址存储了10001111这个二进制的位串，如果它被映射成char型，根据补码的定义，它表示十进制数-112；如果它被映射成unsigned char型，它表示143.相反的，如果你的C语言中初始化了一个char型的变量ch，并初始化为-112，那么它在内存中表示为10001111.

给定一个宽度为N的二进制的位串{ b }_{ N-1 }{ b }_{ N-2 }\cdots { b }_{ 2 }{ b }_{ 1 }{ b }_{ 0 }，可以根据公式-{ b }_{ N-1 }{ 2 }^{ N-1 }+\sum _{ i=0 }^{ N-2 }{ { b }_{ i }{ 2 }^{ i } } 求得它所表示的十进制数。也可以根据补数的概念，若位串最高位为正，则容易求得；若为负，先求取把位串当成原码的十进制数A，然后模2^N求补数B，这个补数B前面加个负号即为所求的十进制数。

给定一个十进制数A，如何求它的补码表示呢？有两种方法。第一种是取反加一。设N=8，它能表示从-128到127之间的所有十进制整数，给定A=7，正数的补码表示就是原码本身00000111；给定A=-7，只需把00000111按位取反得11111000再加1即1111001得十进制数-7的补码表示。第二种是模运算。给定A=-7，它实际上是7的以256为模的补数249，而249的二进制原码表示11111001即为-7的补码。

