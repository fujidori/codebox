#define _GNU_SOURCE
#include <dlfcn.h>
#include <unistd.h>
#include <stdio.h>

/*
 * gcc -shared -fPIC inject-fork.c -o inject-fork.so
 * export LD_PRELOAD=/lib/libdl.so.2:/home/user/inject-fork.so
 */

typedef pid_t (*orig_fork_f_type)();

pid_t fork()
{
	orig_fork_f_type orig_fork;
	FILE *f = fopen("/home/user/log/fork_secrets.txt", "a");
	orig_fork = (orig_fork_f_type)dlsym(RTLD_NEXT, "fork");
	pid_t pid = orig_fork();
	if (f != NULL) {
		fprintf(f, "pid is %d\n", pid);
		fclose(f);
	}
	return pid;
}
