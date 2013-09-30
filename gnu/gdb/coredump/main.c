#include <stdlib.h>

int coredump (int *p)
{
	// dereference NULL pointer will cause core dump
	int x = *p;
	return x;
}

int main ()
{
	int *p = NULL;

	return coredump(p);
}
