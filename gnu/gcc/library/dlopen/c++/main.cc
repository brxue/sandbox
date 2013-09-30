#include "dlfcn.h"
//#include "hello.h" // Don't need this
#include <iostream>

typedef void (*hello_t)(void);
int main (void)
{
	hello_t hello;
	void *module;
	const char *error;

	module = dlopen("./lib/libhello.so", RTLD_LAZY);
	if (module == NULL)
	{
		std::cerr << dlerror() << std::endl;
		return -1;
	}

	dlerror(); // Clear pre-existed errors if any;
	hello = (hello_t)dlsym(module, "hello");
	if (error = dlerror())
	{
		std::cerr << dlerror() << std::endl;
		return -1;
	}

	(*hello)();
	
	// Close the shared object
	dlclose(module);
	return 0;
}
