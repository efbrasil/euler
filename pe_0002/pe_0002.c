#include "stdio.h"
#include "stdlib.h"

#define MAXNUMBER 4000000

int main (int argc, char **argv)
{
	 int current = 1, last = 1, llast = 0, count = 1;
	 int totalsum = 0;
	 int maxnum;

	 if (argc > 1)
	 {
		  maxnum = atoi (argv[1]);
	 } else
	 {
		  maxnum = MAXNUMBER;
	 }

	 while (current < maxnum)
	 {
		  printf ("%02d: %d\n", count, current);
		  if ((current % 2) == 0)
		  {
			   totalsum += current;
		  }
		  
		  llast = last;
		  last = current;
		  current = last + llast;
		  count += 1;
	 }

	 printf ("%d\n", totalsum);

	 return (0);
}
