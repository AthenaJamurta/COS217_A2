/* Athena Jamurta */

#include <stdio.h>
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char pcs[])
{
    size_t uLength = 0; /* counter storing length */
    assert(pcs != NULL);
    while (pcs[uLength] != '\0')
        uLength++;
    return uLength;
}

char *Str_copy(char pcs1[], const char pcs2[])
{
    size_t i = 0; /* counter keeping track of place in array traversals */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    while (pcs2[i] != '\0') {
        pcs1[i] = pcs2[i];
        i++;
    }
    pcs1[i] = '\0';
    return pcs1;
}

char *Str_concat(char pcs1[], const char pcs2[])
{
    size_t i = 0; /* counter keeping track of place in array traversal */
    size_t s1length = Str_getLength(pcs1); /* length of pcs1 */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    while (pcs2[i] != '\0') {
        pcs1[s1length + i] = pcs2[i];
        i++;
    }
    pcs1[s1length + i] = '\0';
    return pcs1;
}

int Str_compare(const char pcs1[],const char pcs2[])
{
    size_t i; /* counter keeping track of place in array traversal */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);

    for (i = 0; pcs1[i] == pcs2[i]; i++) {
        if ((pcs1[i] == '\0') && (pcs2[i] == '\0') ) {
                return 0;
        }
        if ((pcs1[i] != '\0') && (pcs2[i] == '\0')) {
            return 1;
        }
        if ((pcs1[i] == '\0') && (pcs2[i] != '\0') ) {
            return -1;
        }
    }
return (int)(pcs1[i] - pcs2[i]);
}

/* Helper function that takes in a char array pcs1[] and a constant char array pcs2[]
 that both represent a string and returns an int that examines whether the needle
is in the haystack, returning 0 if it is not and != 0 if it is. It also takes in 2
 ints, k1 and k2, that show where we are in pcs1 and pcs2 respectively*/

static int stra_find(const char pcs1[], const char pcs2[], int k1, int k2) {
    int i; /* determines what to return */
    int counter1 = k1; /* counter for pcs1 */
    int counter2 = k2; /* counter for pcs2 */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    while((pcs1[counter1] != '\0') && (pcs2[counter2] != '\0')){
        if (pcs1[counter1] != pcs2[counter2]) {
            return 0;
        }
        counter1++;
        counter2++;
    }
    i = (pcs2[counter2] == '\0');
    return (i);
}

char *Str_search(const char pcs1[], const char pcs2[])
{
    int i; /* stores find */
    int counter1 = 0; /* counter for pcs1 */
    int counter2 = 0; /* counter for pcs2 */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    if (pcs2[0] == '\0') {
        return (char*) pcs1;
    }

    if (pcs1[0] == '\0') {
        return NULL;
    }
    while(pcs1[counter1] != '\0') {
        i = stra_find(pcs1, pcs2, counter1, counter2);
        if (i) {
            return (char*) (pcs1+counter1);
        }
        counter1++;
    }
    return NULL;
}