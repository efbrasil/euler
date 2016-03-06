#include "stdio.h"
#include "stdlib.h"

int pot [] = {1, 10, 100, 1000, 10000, 100000, 1000000}; /* powers of ten */

/* check if n is prime */
int is_prime (int n)
{
	int i;
	
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	if ((n % 2 == 0) || (n % 3 == 0)) return 0;

	i = 5;
	while (i * i <= n)
	{
		if ((n % i == 0) || (n % (i + 2) == 0))
			return 0;
		i += 6;
	}

	return 1;
}

int num_of_digits (int n)
{
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    return 10;
}

/* Get the k-th digit from the number. For the leftmost digit, k = 0. */
int get_digit (int n, int k)
{
	int high, low, base;

	base = pot [k];
	low = n % base;
	high = n % (base * 10);

	return ((high - low) / base);
}

/* Set the k-th digit from the number n to d. For the leftmost digit, k = 0. */
int set_digit (int n, int k, int d)
{
	int old, base;

	old = get_digit (n, k);
	base = n - (old * pot [k]);

	return (base + (pot [k] * d));
}

/* 
   Get the number of primes that are generated if we replace digits
   of the mask of the number "n" by another number.
   If mask is 0b0001 0011, replace digits 0, 1, 4
*/
int num_of_primes (int n, int mask, int print)
{
	int i;
	int cur, primes = 0;
	int digit = 0;
	int tmask;
	int nfound = 0;

	for (i = 0; i < 10; i++)
	{
		cur = n;
		digit = 0;
		tmask = mask;
		while (tmask)
		{
			if (tmask & 0x1)
				cur = set_digit (cur, digit, i);
			digit += 1;
			tmask = tmask >> 1;
		}

		if ((is_prime (cur)) && (cur != n) &&
			(num_of_digits (n) == num_of_digits (cur)))
		{
			primes++;
			if (print) printf ("%d\n", cur);
		}

		if ((is_prime (cur)) && (cur == n))
		{
			nfound = 1;
		}
				
	}
	
	if (is_prime (n))
		primes++;
	
	return (primes * nfound);
}
	
int main (int argc, char **argv)
{
	/* int n = 56003; */
	/* printf ("%d\n", num_of_primes (n, (0x2 + 0x4))); */
	int mask, n, nod, lastmask;
	int bestmask, bestnop, nop, bestn;
	
	bestnop = bestmask = bestn = -1;
	for (n = 1; n < 1000000; n++)
	{
		if (is_prime (n))
		{
			/* 
			   mask has to go from 0 (no changes) to 0b11..11
			   the last mask will have as many ones as the number of digits
			   in the number, which is (1 << num_of_digits (n)) - 1
			 */
			nod = num_of_digits (n);
			lastmask = (1 << nod) - 1;

			for (mask = 0; mask <= lastmask; mask++)
			{
				/* printf ("0x%02x => %d primes\n", */
				/* 		mask, num_of_primes (n, mask)); */

				nop = num_of_primes (n, mask, 0);
				if (nop > bestnop)
				{
					bestnop = nop;
					bestmask = mask;
					bestn = n;
					printf ("Best: n = %d, nop = %d, mask = 0x%02x\n",
							n, nop, mask);
					num_of_primes (n, mask, 1);
					if (bestnop >= 8) return (0);
				}
				
			}
		}
	}
			
	return (0);
}
