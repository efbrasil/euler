#include "stdio.h"
#include "stdlib.h"

int diff (int n)
{
	int i, sum = 0, sqsum = 0;

	for (i = 1; i <= n; i++)
	{
		sum = sum + i;
		sqsum = sqsum + (i * i);
	}

	printf ("%d, %d, %d, %d\n", n, sum * sum, sqsum, (sum * sum) - sqsum);

	return (sum * sum - sqsum);
}

int main (int argc, char **argv)
{
	int lastnum = 10;
	int i;
	if (argc > 1) lastnum = atoi (argv [1]);

	for (i = 1; i <= lastnum; i++)
		diff (i);
	
	return (0);
}
