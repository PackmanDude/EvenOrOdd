#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Must be at least 1 argument passed\n");
		return -1;
	}

	int n = atoi(argv[1]);
	printf("%s\n", (n&1 == 1) ? "Odd" : "Even");
	return 0;
}
