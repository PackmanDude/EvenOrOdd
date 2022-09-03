#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "%s: Must be at least 1 argument passed\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char *ptr;
	errno = 0;
	for (int i = 1; i < argc; ++i)
	{
		long n = strtol(argv[i], &ptr, 0);
		long *p = &n;

		if (*ptr != '\0')
		{
			fprintf(stderr, "Not a number.\n");
			errno = 1;
			continue;
		}

		if ((*p == LONG_MIN || *p == LONG_MAX) && errno == ERANGE)
		{
			perror(argv[0]);
			return EXIT_FAILURE;
		}

		if ((*p & 1) == 0)
		{
			printf("Even\n");
		}

		if ((*p & 1) == 1)
		{
			printf("Odd\n");
		}
	}
	return EXIT_SUCCESS;
}
