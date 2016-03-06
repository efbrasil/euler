#include "stdio.h"

#define MAXNUMBER 1000

int sum_of_divisors (int number, int divisor)
{
	 /* 10 has (10 / 3) divisors that are multiple of 3 */
	 /* sum_of_divisors (10) = 3 + 6 + 9 = 3 * (1 + 2 + 3) */
	 /* (1 + 2 + 3 + ... + n) = (1 + n) * n / 2 */
	 int num_of_divisors = number / divisor;
	 return divisor * (1 + num_of_divisors) * num_of_divisors / 2;
}

int main (int argc, char **argv)
{
	 int mult_of_3, mult_of_5, mult_of_15;

	 mult_of_3 = sum_of_divisors (MAXNUMBER - 1, 3);
	 mult_of_5 = sum_of_divisors (MAXNUMBER - 1, 5);
	 mult_of_15 = sum_of_divisors (MAXNUMBER - 1, 15);

	 printf ("%d\n", mult_of_3 + mult_of_5 - mult_of_15);

	 return (0);
}
	 
int main_brute_force (int argc, char **argv)
{
	 int sum = 0;
	 int i;

	for (i = 1; i < MAXNUMBER; i++)
	{
		 if (((i % 3) == 0) || ((i % 5 == 0)))
		 {
			  /* printf ("%d\n", i); */
			  sum += i;
		 }
	}

	printf ("Sum = %d\n", sum);
	return (0);
}

