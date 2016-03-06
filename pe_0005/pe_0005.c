#include "stdio.h"
#include "stdlib.h"

long gcd (long i, long j)
{
	int tmp, big, small;

	if (i == j) return i;

	if (i > j)
	{
		big = i;
		small = j;
	} else
	{
		big = j;
		small = i;
	}
	
	while (small)
	{
		tmp = small;
		small = big % small;
		big = tmp;
	}

	return (big);
}

long lcm (long i, long j)
{
	return (i * j) / gcd (i, j);
}

int main (int argc, char **argv)
{
	long i = 1;
	long accum = i;
	int lastnum = 20;

	if (argc > 1) lastnum = atoi (argv [1]);
	
	while (i <= lastnum)
	{
		/* printf ("(%ld, %ld) - ", i, accum); */
		accum = lcm (accum, i);
		/* printf ("%ld\n", accum); */
		i += 1;
	}

	printf ("%ld\n", accum);
	
	return (0);
}
