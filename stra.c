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
 that both represent a string and outputs an int that examines whether the needle
is in the haystack. It also takes in an int k that shows where we are in the haystack*/

static int find(const char pcs1[], const char pcs2[], int k1, int k2) {
    int i; /* determines what to return */
    int j1 = k1; /* counter for pcs1 */
    int j2 = k2; /* counter for pcs2 */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    while((pcs1[j1] != '\0') && (pcs2[j2] != '\0')){
        if (pcs1[j1] != pcs2[j2]) {
            return 0;
        }
        j1++;
        j2++;
    }
    i = (pcs2[j2] == '\0');
    return (i);
}

char *Str_search(const char pcs1[], const char pcs2[])
{
    int i; /* stores find */
    int j1 = 0; /* counter for pcs1 */
    int j2 = 0; /* counter for pcs2 */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    if (pcs2[0] == '\0') {
        return (char*) pcs1;
    }

    if (pcs1[0] == '\0') {
        return NULL;
    }
    while(pcs1[j1] != '\0') {
        i = find(pcs1, pcs2, j1, j2);
        if (i) {
            return (char*) (pcs1+j1);
        }
        j1++;
    }
    return NULL;
}