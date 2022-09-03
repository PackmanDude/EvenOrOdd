#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Must be at least 1 argument passed\n");
		exit(EXIT_FAILURE);
	}

	char *p;
	errno = 0;
	for (int i = 1; i < argc; ++i)
	{
		long n = strtol(argv[i], &p, 0);

		if (*p != '\0')
		{
			fprintf(stderr, "Pass a number.\n");
			exit(EXIT_FAILURE);
		}

		if ((n == LONG_MIN || n == LONG_MAX) && errno == ERANGE)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}

		if ((n & 1) == 0)
		{
			printf("Even\n");
		}

		if ((n & 1) == 1)
		{
			printf("Odd\n");
		}
	}
	return EXIT_SUCCESS;
}
