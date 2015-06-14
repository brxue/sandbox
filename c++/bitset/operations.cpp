#include <bitset>
#include <cassert>
#include <iostream>
using namespace std;

void operations()
{
	bitset<32> a; // 32bits, each bit initialized as 0
	bitset<32> b(0x55aa); // 32bits initialized as 0x000055aa
	
	assert(a.size() == 32);
	assert(b.size() == 32);
	assert(a.count() == 0); // count all ones
	assert(b.count() == 8); // count all ones
	assert(a.none() == 1); // no bit has one?
	assert(b.none() == 0); // no bit has one?
	assert(a.any() == 0); // has bit as one?
	assert(b.any() == 1); // has bit as one?
	assert(b.test(15) == 0); // b[15] is one?
	assert(b.test(14) == 1); // b[14] is one?
	
	b.flip(); // toggle all bits
	assert(b.to_ulong() == 0xffffaa55);

	b.flip(); // toggle all bits
	assert(b.to_ulong() == 0x55aa);

	b.flip(15); // toggle all bits
	assert(b.to_ulong() == 0xd5aa);

	b.reset(15); // reset bit[15] to 0
	assert(b.to_ulong() == 0x55aa);

	b.reset(); // reset all bits to 0
	assert(b.to_ulong() == 0);
}

int main()
{
	operations();
	return 0;
}
