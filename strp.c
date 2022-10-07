#include <stdio.h>
#include <stddef.h>
#include <assert.h>

size_t Str_getLength(const char *pcSrc)
{
    const char *pcEnd; /* pointer pointing to end of string */
    assert(pcSrc != NULL);
    pcEnd = pcSrc;
    while (*pcEnd != '\0')
        pcEnd++;
    return (size_t)(pcEnd - pcSrc);
}

char *Str_copy(char *s1, const char *s2) {
    char *s2Copy = (char*) s2;
    char *pcEnd = s2Copy; /* pointer pointing to end of string */
    char *pcPointsToS1 = s1; /* pointer pointing to s1 */
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
    char *pcEnd = s1; /* pointer pointing to end of string */
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
    char *pcEnd = (char*) s1Copy; /* pointer pointing to end of string */
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
    size_t i = 0; /* counter tracking that traversal doesn't surpass s1 length */
    size_t j; /* counter tracking that traversal doesn't surpass s2 length */
    size_t k; /* counter tracking that traversal doesn't surpass s1 length
 *  in inner loop*/
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
