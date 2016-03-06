#include "stdio.h"
#include "stdlib.h"

int main (int argc, char **argv)
{
	 int i = 1;
	 int largest = 1;
	 long maxnum = 600851475143;
	
	 if (argc > 1)
		  maxnum = atol (argv[1]);

	 while (i <= maxnum)
	 {
		  i = i + 1;

		  if (maxnum % i == 0)
		  {
			   printf ("New prime: %d\n", i);
			   largest = i;
		  }
		  
		  while (maxnum % i == 0)
			   maxnum = maxnum / i;
	 }

	 printf ("%d\n", largest);
	 return (0);
}
