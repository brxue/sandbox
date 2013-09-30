#include <bitset>
#include <cassert>
#include <iostream>

using namespace std;

void constructor()
{
	bitset<16> a;
	bitset<32> b(0x55555555);
	bitset<8>  c(string("11110000"));
	bitset<1024> d(0xffff);
	bitset<8> e(0x1234);
	bitset<4> f(string("10010101"), 2, 4); // 4bits start from string[2]

	assert(a.size() == 16);
	assert(b.size() == 32);
	assert(c.size() == 8);
	assert(d.size() == 1024);
	assert(e.size() == 8);

	for (unsigned int i = 0; i != 16; ++i)
		assert(a[i] == 0);

	for (unsigned int i = 0; i != 32; i += 2)
		assert(b[i] == 1);

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

void operations()
{
	bitset<32> a;
	bitset<32> b(0x55aa);
	
	assert(a.size() == 32);
	assert(b.size() == 32);
	assert(a.count() == 0);
	assert(b.count() == 8);
	assert(a.none() == 1);
	assert(b.none() == 0);
	assert(a.any() == 0);
	assert(b.any() == 1);
	assert(b.test(15) == 0);
	assert(b.test(14) == 1);
	
	b.flip();
	assert(b.to_ulong() == 0xffffaa55);

	b.flip();
	assert(b.to_ulong() == 0x55aa);

	b.flip(15);
	assert(b.to_ulong() == 0xd5aa);

	b.reset(15);
	assert(b.to_ulong() == 0x55aa);

	b.reset();
	assert(b.to_ulong() == 0);
}

int main()
{
	constructor();
	operations();
	return 0;
}


