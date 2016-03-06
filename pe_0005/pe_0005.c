#include "stdio.h"
#include "stdlib.h"

int gcd (int i, int j)
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

	return (big)
}

/* int lcm (int i, int j) */
/* { */

	
/* } */

int main (int argc, char **argv)
{
	int i, int j;

	i = 6; j = 12;
	printf ("(%02d, %02d): %d\n", i, j, gcd (i, j));
	
	return (0);
}
