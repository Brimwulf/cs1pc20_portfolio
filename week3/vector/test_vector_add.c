#include <assert.h>
#include "vector.h"

/** A simple test framework for vector library
* we will be improving on this later
*/
int main(void) {
/** xvec and yvec will be inputs to our vector arithmetic routines
* zvec will take the return value
*/
   int xvec[SIZ] = {1,2,3};
   int yvec[SIZ] = {5,0,2};
   int zvec[SIZ];
   add_vectors(xvec,yvec,zvec);
   /** We want to check each element of the returned vector
   */
   assert(6==zvec[0]);
   assert(2==zvec[1]);
   assert(5==zvec[2]);
   /** IF the asserts worked, there wasn't an error so 0 is returned.
   */
   return 0;
}

