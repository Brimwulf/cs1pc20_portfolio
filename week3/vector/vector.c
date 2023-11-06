#include "vector.h"

/** A simple fixed vector addition routine
* Add each element of x to corresponding element of y, storing answer in z
* It is the calling codes responsibility to ensure they are the right size
* and that they have been declared
* We return and error code (0 meaning there was no error), but will add the
* program logic to handle actual errors later
*/
int add_vectors(int x[], int y[], int z[]) {

   for (int i=0; i<SIZ; i++)
      z[i]=x[i]+y[i];
   return 0;
}

