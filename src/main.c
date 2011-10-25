/******************************* Schlaser Header ******************************
Purpose: 
   Program Frame -- "Home is wherever I'm with you."
Reference:
   None
Programmers:
   E. Kent Golding -- Oct 2011 -- Initial Implementation
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "schlaser.h"

/* 
 * May Want this at a later time
#include <gconf/gconf-client.h>
GConfClient *gconf;
#define GCONF_NAME(x) "/apps/subsurface/" #x
 * END Comment block
 */

/** Helper Function(s) **/
static void parse_args(const char *arg)
{
   const char *p = arg+1;
   do {
      switch (*p) {
      case 'v':
//         verbose++;
         continue;
      case '-':
         /* long options with -- */
         if (strcmp(arg,"--version") == 0) {
            /* FIX ME: hook to report version. This will come later */
            return;
         }
         /* fallthrough */
      default:
         fprintf(stderr, "Bad argument '%s'\n", arg);
         exit(1);
      }
   } while (*++p);
}

int main(int argc, char **argv)
{
   int ii;

   init_ui(argc, argv);

   for (ii=1; ii<argc; ii++) {
      const char *a = argv[ii];

      if (a[0] == '-') {
         parse_args(a);
         continue;
      }
      GError *error = NULL;

      if (error != NULL)
      {
       //  report_error(error);
         g_error_free(error);
         error = NULL;
      }
   }

   run_ui();
   return 0;
}
