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
    assert(s1 != NULL);
    assert(s2 != NULL);
    while(*s1 == *s2) {
        if ((*(s1) == '\0')&&(*(s2) != '\0')) {
            return -1;
        }
        if ((*(s1) == '\0')&&(*(s2) == '\0')) {
            return 0;
        }
        if ((*(s1) != '\0')&&(*(s2) == '\0')) {
            return 1;
        }

        s2++;
        s1++;
    }
    return (int)(*s1 - *s2);
}



static int find(const char *s1, const char *s2) {
    int i; /* determines what to return */
    assert(s1 != NULL);
    assert(s2 != NULL);
    while((*s1 != '\0') && (*s2!= '\0')){
        if (*s1 != *s2) {
            return 0;
        }
        s1++;
        s2++;
    }
    i = *s2 == '\0';
    return (i);
}

char *Str_search(const char* s1, const char* s2) {
    int i; /* stores find */
    assert(s1 != NULL);
    assert(s2 != NULL);
    if (*s1 == '\0') {
        return (char*) s1;
    }
    while(*s1 != '\0') {
        i = find(s1, s2);
        if (i) {
            return (char*) s1;
        }
        s1++;
    }
    return NULL;
}
