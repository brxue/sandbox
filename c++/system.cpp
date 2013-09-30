#include <cstdlib>
#include <iostream>

using namespace std;

int main ()
{
	cout << "Checking if a command processor is available..." << endl;
	if (system(NULL))
		cout << "...command processor existed. " << endl;
	else 
	{
		cout << "There doesn't exist a command processor to execute the command specified to system()." << endl;
		return 1;
	}
	
	// system() will print the output of the specified command
	if (system("ls -la") == 0)
		cout << "Command executed successfully." << endl;

	return 0;
}
