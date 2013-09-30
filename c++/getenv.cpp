#include <cstdlib>
#include <iostream>

int main ()
{
	char* p = NULL;

	p = getenv("PATH");
	
	if (p != NULL)
		std::cout << p << std::endl;
	else
		std::cout << "PATH not defined!" << std::endl;

	return 0;
}
