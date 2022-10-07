#include <stdio.h>
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char *pcSrc)
{
    const char *pcEnd;
    assert(pcSrc != NULL);
    pcEnd = pcSrc;
    while (*pcEnd != '\0')
        pcEnd++;
    return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *s1, const char *s2) {

    char *pcEnd = s2;
    char *pcPointsToS1 = s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pcEnd != '\0') {
        *pcPointsToS1 = *pcEnd;
        pcEnd++;
        pcPointsToS1++;

    }
    *pcPointsToS1 = '\0';
    return s1;
}

char *Str_concat(char* s1, const char* s2)
{

    char *pcEnd = s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pcEnd != '\0') {
        pcEnd++;
    }
    while (*s2 != '\0') {
        *pcEnd = *s2;
        pcEnd++;
        s2++;
    }
    *pcEnd = '\0';
    return s1;
}

int Str_compare(const char* s1, const char* s2)
{
    int i;
    char *pcEnd = s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pcEnd != '\0') {
        pcEnd++;
    }
    for (i = 0; *s1 == *s2; i++) {
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return (int)(s1 - s2);
}



char *Str_Search(const char* s1, const char* s2)
{
    size_t i = 0;
    size_t j = 0;
    size_t s1Length = Str_getLength();

    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    if (*pcs2 == '\0') return (char*)pcs1;






}