#include <iostream>
#include <unistd.h>
#include <cstdlib>

using namespace std;

void print_cwd1(void)
{
	char cwd[1024];
	if (getcwd(cwd, 1024) != NULL)
		cout << cwd << endl;
	else 
		cout << "ERROR: can't get the current working directory." << endl;
}

void print_cwd2(void)
{
	char *cwd = getcwd(NULL, 0);
	if (cwd != NULL)
	{
		cout << cwd << endl;
		free(cwd); // free the memory allocated in getcwd()
	}
	else 
		cout << "ERROR: can't get the current working directory." << endl;
}

int main ()
{
	print_cwd1();
	print_cwd2();

	return 0;
}
