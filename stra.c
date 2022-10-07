#include <stdio.h>
#include <assert.h>
/* */
size_t Str_getLength(const char pcs[])
{
    size_t uLength = 0;
    assert(pcs != NULL);
    while (pcs[uLength] != '\0')
        uLength++;
    return uLength;
}

char *Str_copy(char pcs1[], const char pcs2[])
{
    size_t i = 0;
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
    size_t i = 0;
    size_t s1length = Str_getLength(pcs1);
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    while (pcs2[i] != '\0') {
        pcs1[s1length + i] = pcs2[i];
        i++;
    }
    pcs1[s1length + i] = '\0';
    return pcs1;
}

int Str_compare(const char pcs1[], const char pcs2[])
{
    size_t i;

    assert(pcs1 != NULL);
    assert(pcs2 != NULL);

    for (i = 0; pcs1[i] == pcs2[i]; i++) {
        if (pcs1[i] == '\0') {
                return 0;
        }
    }
    return pcs1[i] - pcs2[i];
}


char *Str_search(const char pcs1[], const char pcs2[])
{
    size_t s1length = Str_getLength(const char pcs1[]);
    size_t s2length = Str_getLength(const char pcs2[]);
    size_t i = 0;
    size_t j;
    size_t k;
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    if (pcs2[0] == '\0') return (char*)&pcs1[0];
    while ( i < s2length) {
        j = 0;
        k = i;
        if ((s1length + 1 - i) < s2length) return NULL;
        while ((k < s1length) && (j < s2length) && (pcs1[i] == pcs2[i])) {
            k++;
            j++;
            if (j == s2length) return (char*)&pcs1[i];
        }
        i++;
    }
    return NULL;
}