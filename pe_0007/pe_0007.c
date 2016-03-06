#include "stdio.h"
#include "stdlib.h"

int main (int argc, char **argv)
{
	int *primes;
	int pnum = 0;
	int lastnum = 6;
	int i, pp, notprime;
	
	if (argc > 1) lastnum = atoi (argv [1]);

	primes = malloc (sizeof (primes [0]) * lastnum);
	
	pp = 1;
	while (pnum < lastnum)
	{
		pp += 1;				/* pp is the number being tested */

		notprime = 0;
		for (i = 0; i < pnum; i++)
			if (pp % primes [i] == 0) /* if pp is a multiple of a prime, then 
										 it's not prime */
				notprime = 1;
		if (!notprime)
		{
			primes [pnum] = pp;
			pnum += 1;
		}
	}

	for (i = 0; i < pnum; i++)
		printf ("%d\n", primes [i]);

	free (primes);
	
	return (0);
}
