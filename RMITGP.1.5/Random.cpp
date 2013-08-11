#include <cstdlib>
#include <sys/types.h>
#include <time.h>
#include <limits.h>
/* This has been added for getpid command. 15/8/05 - Michael Foster -
 * micfoste@cs.rmit.edu.au*/
#include <unistd.h>

/*
 * The following line has been added for gettimeofday command, to make the
 * program compatible with Linux. 2007-09-21 - Pasquale Barile -
 * bpasqual@cs.rmit.edu.au
 */
#include <sys/time.h>
#include "Random.h"

Random::Random(int seed)
{
   if (seed == 0)
   {
	  /* This is the new code for seeding the random number generator. The old
	   * code would have the same seed for any process that started in the same
	   * second. This new code will be different down to the microsecond.
	   * 
	   * Added 15/8/05
	   * Author: Michael Foster (micfoste@cs.rmit.edu.au)
	   * Credit: Christian Stigen Larsen, http://csl.sublevel3.org/c++/
	   */
	  struct timeval tv; // C requires "struct timval" instead of just "timeval"
	  gettimeofday(&tv, 0);

	  // use BOTH microsecond precision AND pid as seed
	  long int n = tv.tv_usec * getpid(); 
	  srand(n);
	  
/*  THIS CODE WAS BAD. ANY RUN THAT STARTED IN THE SAME GENERATION WOULDN'T BE
 *  RANDOM:
	srand(time(NULL));
 */
   }
   else
      srand(seed);
}

Random::~Random()
{
}

long Random::randNum() const
{
   return rand();
}

long Random::max() const
{
   return RAND_MAX; 
}

double Random::randReal() const
{
   return ((double)rand()) / max();
}
