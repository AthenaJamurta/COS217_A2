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

static int find(const char pcs1[], const char pcs2[]) {
    int i; /* determines what to return */
    int j = 0; /* counter */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    while((pcs1[j] != '\0') && (pcs2[j] != '\0')){
        if (pcs1[j] != pcs2[j]) {
            return 0;
        }
        j++;
    }
    i = pcs2[j] == '\0';
    return (i);
}

char *Str_search(const char pcs1[], const char pcs2[])
{
    int i; /* stores find */
    int j = 0; /* counter */
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    if (s2[0] == '\0') {
        return (char*) pcs1;
    }

    if (pcs1[0] == '\0') {
        return NULL;
    }
    while(s1[j] != '\0') {
        i = find(pcs1, pcs2);
        if (i) {
            return (char*) pcs1;
        }
        j++;
    }
    return NULL;
}