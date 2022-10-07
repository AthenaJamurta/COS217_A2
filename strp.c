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
    const char *s1Copy = (char*) s1;
    char *pcEnd = (char*) s1Copy;
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
    size_t j;
    size_t k;
    const char *s1Copy = (char*) s1;
    const char *s2Copy = (char*) s2;
    size_t s1Length = Str_getLength(s1Copy);
    size_t s2Length = Str_getLength(s2Copy);
    assert(s1 != NULL);
    assert(s2 != NULL);
    if (*s2 == '\0') return (char *) s1;
    while (i < (s1Length - s2Length)) {
        k = i;
        j = 0;
        if ((s1Length + 1 - i) < s2Length) return NULL;
        while ((k < s1Length) && (j < s2Length) && (*s1Copy == *s2Copy))
        {
            k++;
            j++;
            if (j == s2Length) return (char*) (s1Copy + i);
        }
        i++;
    }
    return NULL;
}
