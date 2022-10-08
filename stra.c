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



char *Str_search(const char pcs1[], const char pcs2[])
{
    int contains;
    size_t i; /* counter for outer while */
    size_t j; /* counter for inner while */
    size_t s1Length; /* s1's length */
    size_t s2Length; /*s2's length */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    s1Length = Str_getLength(pcs1);
    s2Length = Str_getLength(pcs2);
    i = 0;
    if (pcs2[0] == '\0') return (char*)pcs2;
    while (i < s1Length - s2Length) {
        contains = 1;
        i++;
        j = 0;
        while (j<s2Length) {
            if (pcs1[j+i] != pcs2[j]) {
                contains = 0;
                j++;
            }
            if (contains) return (char*)(pcs1+i);
        }
    }
return NULL;
}