#include <stdio.h>

int main(int argc, char *argv[])
{
	int arr[5] = {1};
	printf("The address of arr is %p\n", arr);
	printf("The address of &arr is %p\n", &arr);

	printf("The address of arr+1 is %p\n", arr + 1);
	printf("The address of &arr+1 is %p\n", &arr + 1);

	return 0;
}

