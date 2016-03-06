#include "stdio.h"
#include "stdlib.h"

/* 100 * 100 = 10.000 */
/* 999 * 999 = 998.001 */

int is_palindrome (int n)
{
	 int nod = 1;				/* number of digits */
	 int d[6], i;
	 int last_pow_of_ten, cur_pow_of_ten;

	 if (n < 100000)
		  nod = 5;
	 else
		  nod = 6;

	 cur_pow_of_ten = 1;
	 
	 for (i = 0; i < 6; i++)
	 {
		  last_pow_of_ten = cur_pow_of_ten;
		  cur_pow_of_ten = last_pow_of_ten * 10;

		  d [i] = (((n % cur_pow_of_ten) - (n % last_pow_of_ten))) / last_pow_of_ten;
	 }

	 for (i = 0; i < nod / 2; i++)
		  if (d [i] != d [nod - 1 - i]) return 0;

	 return (1);
}

int main (int argc, char **argv)
{
	 int i, j;
	 int largest = 0;

	 for (i = 100; i < 999; i++)
		  for (j = 100; j < 999; j++)
			   if (is_palindrome (i * j))
			   {
					if ((i * j) > largest)
					{
						 printf ("%d * %d - %d\n", i, j, i * j);
						 largest = i * j;
					}
			   }
	 

	 /* printf ("%d\n", largest); */
	 return (0);
}
