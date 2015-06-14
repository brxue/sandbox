#include <bitset>
#include <cassert>
#include <iostream>
using namespace std;

void constructor()
{
	bitset<16> a; // bitset with 16 binary bits, each intialized as 0
	bitset<32> b(0x55555555); // constructed from an integer
	bitset<8>  c(string("11110000")); // constructed from a binary string
	bitset<1024> d(0xffff); // bitset with 1024 bits, the LSB 16bits is 0xffff
	bitset<8> e(0x1234); // bitset with 8 bits, initialized with 0x34(0x12 discarded)
	bitset<4> f(string("10010101"), 2, 4); // 4bits start from string[2]

	assert(a.size() == 16);
	assert(b.size() == 32);
	assert(c.size() == 8);
	assert(d.size() == 1024);
	assert(e.size() == 8);

	for (unsigned int i = 0; i != 16; ++i)
		assert(a[i] == 0);

	for (unsigned int i = 0; i != 32; i += 2)
    {
		assert(b[i] == 1);
        assert(b[i+1] == 0);
    }

	assert(c.to_ulong() == 0xf0);

	for (unsigned int i = 0; i != 1024; ++i)
	{
		if (i < 16)
			assert(d[i] == 1);
		else 
			assert(d[i] == 0);
	}

	assert(e.to_ulong() == 0x34);
	assert(f.to_ulong() == 0x5);
}

int main()
{
	constructor();
	return 0;
}
