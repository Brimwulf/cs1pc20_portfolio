#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/** defining a set of constant values */
#define COM_SIZ 60
#define ARG_SIZ 1024
#define RES_SIZ 1024

int main (int argc, char *argv[]) {

/** the main function calls an existing executable and checks the outputs to standard outputs
    meet the expected values. It should be called with 
    test_outputs <file name which contains test definitions> */

   FILE *fp; /** fp is a pointer that gives access to the file descriptor of the pipe */
   FILE *tests;
   char command[COM_SIZ];
   char arguments[ARG_SIZ];
   char expected[RES_SIZ];
   char actual[RES_SIZ];
   char command_line[COM_SIZ + ARG_SIZ];

/** this part tries to open the executable listed on the command line */
   tests=fopen(argv[1], "rt");
   if (tests==NULL) {
      printf("error opening file %s\n", argv[1]);
      return 1;
   }

/** We'll use a while loop to read each line from a file.
*Structured as:
*Command to run
*inputs
*expected output */

   while (fgets(command, COM_SIZ, tests) !=NULL) {
      fgets(arguments, ARG_SIZ, tests);
      fgets(expected, RES_SIZ, tests);
      strtok(command, "\n");
      snprintf(command_line, sizeof command_line, "%s %s", command, arguments);

/** now using a pipe file to call a command, with it's arguments, and compare the result
to the expected result. "popen" is used to open the pipe file.*/

      fp=popen(command_line, "r");
      if (fp == NULL) {
         printf("failed to run command\n");
         exit(1);
      }

      char message[RES_SIZ + RES_SIZ + 21];

      while(fgets(actual, sizeof(actual), fp) != NULL) {
         snprintf(message, sizeof message, "%s %s %s %s",
            "Expected", expected, "and got", actual);
         /** a message saying what got vs what 
             expected remember doesn't have to 
             be on the same line */
         printf("%s", message);
         
         /** we use an if statement here because we want the test suit to keep running */
         if(!strcmp(actual, expected)) {
            printf("OK/n");
         }
         else {
            printf("FAILED\n");
         }
      }
      pclose(fp); /** Close the file handle to prevent using up vm resources */
   }
   fclose(tests);
/**}*/
   return 0;
}
