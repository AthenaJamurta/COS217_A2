/*--------------------------------------------------------------------*/
/* replace.c                                                          */
/* Author: Athena Jamurta                                                        */
/*--------------------------------------------------------------------*/

#include "str.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


/*--------------------------------------------------------------------*/

/* If pcFrom is the empty string, then write string pcLine to stdout
   and return 0.  Otherwise, write string pcLine to stdout with each
   distinct occurrence of string pcFrom replaced with string pcTo,
   and return a count of how many replacements were made.  Make no
   assumptions about the maximum number of replacements or the
   maximum number of characters in strings pcLine, pcFrom, or pcTo. */

static size_t replaceAndWrite(const char *pcLine,
                              const char *pcFrom, const char *pcTo) {
    size_t i = 0;
    char *pcStartOfTo;
    char *pcStartOfString;
    assert(pcLine != NULL);
    assert(pcTo != NULL);
    assert(pcFrom != NULL);

    pcStartOfTo = (char*)pcTo;

    if (*pcFrom != '\0') {


        pcStartOfString = Str_search(pcLine, pcFrom);

        while ((*pcLine != '\0') && (pcStartOfString != NULL))
        {
            while (pcLine != pcStartOfString) {
                putc(*pcLine, stdout);
                pcLine++;
            }
            while (*pcTo != '\0') {
                putc(*pcTo, stdout);
                pcTo++;
            }

            i++;
            pcLine += Str_getLength(pcFrom);
            pcTo = pcStartOfTo;
            pcStartOfString = Str_search(pcLine, pcFrom);

        }
    }


    while(*pcLine != '\0') {
    putc(*pcLine, stdout);
    pcLine++;
    }

return i;
}

/*--------------------------------------------------------------------*/

/* If argc is unequal to 3, then write an error message to stderr and
   return EXIT_FAILURE.  Otherwise...
   If argv[1] is the empty string, then write each line of stdin to
   stdout, write a message to stderr indicating that 0 replacements
   were made, and return 0.  Otherwise...
   Write each line of stdin to stdout with each distinct occurrence of
   argv[1] replaced with argv[2], write a message to stderr indicating
   how many replacements were made, and return 0.
   Assume that no line of stdin consists of more than MAX_LINE_SIZE-1
   characters. */

int main(int argc, char *argv[])
{
   enum {MAX_LINE_SIZE = 4096};
   enum {PROPER_ARG_COUNT = 3};

   char acLine[MAX_LINE_SIZE];
   char *pcFrom;
   char *pcTo;
   size_t uReplaceCount = 0;

   if (argc != PROPER_ARG_COUNT)
   {
      fprintf(stderr, "usage: %s fromstring tostring\n", argv[0]);
      return EXIT_FAILURE;
   }

   pcFrom = argv[1];
   pcTo = argv[2];

   while (fgets(acLine, MAX_LINE_SIZE, stdin) != NULL) {

       uReplaceCount += replaceAndWrite(acLine, pcFrom, pcTo);

   }

   fprintf(stderr, "%lu replacements\n", (unsigned long)uReplaceCount);
   return 0;
}
