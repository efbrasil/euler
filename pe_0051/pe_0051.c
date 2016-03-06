#include "stdio.h"
#include "stdlib.h"

int pot [] = {1, 10, 100, 1000, 10000, 100000, 1000000}; /* powers of ten */
int *kp;

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
   "changes [0]"  .. "changes [nchanges - 1]" of the number "n" by another
   number.
*/
int num_of_primes (int n, int nchanges, int *changes, int *first)
{
	int i, j;
	int cur, primes = 0;

	cur = n;

	for (i = 0; i < 10; i++)
	{
		cur = n;
		for (j = 0; j < nchanges; j++)
			cur = set_digit (cur, changes [j], i);
		if (primes == 0) *first = cur;
		if (is_prime (cur)) primes++;
	}
	
	return (primes);

}

int main (int argc, char **argv)
{
	/* int n = 123456; */
	/* int k; */

	/* for (k = 0; k < 6; k++) */
	/* 	printf ("get_digit (%d, %d) = %d\n", n, k, get_digit (n, k)); */
	
	/* for (k = 0; k < 6; k++) */
	/* 	printf ("set_digit (%d, %d, 7) = %d\n", n, k, set_digit (n, k, 7)); */

	/* int i; */
	/* for (i = 1; i <= 30; i++) */
	/* 	printf ("is_prime (%d) = %d\n", i, is_prime (i)); */

	int n = 56003, first;
	int changes[] = {1, 2};

	printf ("%d\n", num_of_primes (n, 2, changes, &first));
	printf ("First: %d\n", first);

	return (0);
}
