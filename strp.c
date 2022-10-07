#include <stdio.h>
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char *pcSrc)
{
    char *pcSrcCopy = (char*) pcSrc;
    const char *pcEnd;
    assert(pcSrc != NULL);
    pcEnd = pcSrcCopy;
    while (*pcEnd != '\0')
        pcEnd++;
    return (size_t)(pcEnd - pcSrcCopy);
}

char *Str_copy(char *s1, const char *s2) {
    char *s2Copy = (char*) s2;
    char *pcEnd = s2Copy;
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
    char *s2Copy = (char*) s2;
    char *pcEnd = s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pcEnd != '\0') {
        pcEnd++;
    }
    while (*s2Copy != '\0') {
        *pcEnd = *s2Copy;
        pcEnd++;
        s2Copy++;
    }
    *pcEnd = '\0';
    return s1;
}

int Str_compare(const char* s1, const char* s2)
{
    int i;
    char *s1Copy = (char*) s1;
    char *pcEnd = s1Copy;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pcEnd != '\0') {
        pcEnd++;
    }
    for (i = 0; *s1Copy == *s2; i++) {
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return (int)(s1Copy - s2);
}



char *Str_Search(const char* s1, const char* s2) {
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;
    char *s1Copy = (char*) s1;
    char *s2Copy = (char*) s2;
    size_t s1Length = Str_getLength(s1Copy);
    size_t s2Length = Str_getLength(s2Copy);
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    if (*pcs2 == '\0') return (char *) pcs1;
    while (i < (s1Length - s2Length)) {
        k = i;
        j = 0;
        if ((s1length + 1 - i) < s2length) return NULL;
        while (k < s1length) && (j < s2length) && (*s1Copy == *s2Copy)
        {
            k++;
            j++;
            if (j == s2length) return *(s1Copy + i);
        }
        i++;
    }
    return NULL;
}






}