#include <stdio.h>

int main(int argc, char *argv[])
{
	char buf[10];
	const char *fmt = "%'d\n";
	int v = 12345678;

	// n = 9 if LC_NUMERIC=C
	// buffer overflow if setlocale(LC_NUMERIC, "en_US.UTF-8"); in any threads
	int n = snprintf(NULL, 0, fmt, v);
	if (0 <= n && n < 10) {
		sprintf(buf, fmt, v);
	}
	printf("%d\n", n);

	return 0;
}
