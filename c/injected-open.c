#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdio.h>

/*
 * gcc -shared -fPIC injected-open.c -o injected-open -ldl
 * LD_PRELOAD=$PWD/injected-open.so gnome-calculator
 */

typedef int (*orig_open_f_type)(const char *pathname, int flags);

int open(const char *pathname, int flags, ...)
{
	// injected code
	printf("The victim used open(...) to access '%s'!!!\n", pathname);

	orig_open_f_type orig_open;
	orig_open = (orig_open_f_type)dlsym(RTLD_NEXT, "open");
	return orig_open(pathname, flags);
}
