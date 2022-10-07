

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
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pcEnd != '\0') {
        *(s1+i) = *(s2+i);
        pcEnd++;
    }
    return s1;
}

char *Str_concat(char *s1, const char *s2)
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
    return s1;
}

int Str_compare(char *s1, char *s2)
{
    int i;
    char *pcEnd = s1;
    assert(s1 != NULL);
    assert(s2 != NULL);
    while (*pcEnd != '\0') {
        pcEnd++;
    }
    for (i = 0; s1[i] == s2[i]; i++) {
        if (s1[i] == '\0') {
            return 0;
        }
    }
    return s1[i] - s2[i];
}



char *Str_Search(const char *pcs1, const char *pcs2)
{
    int i;
    assert(pcs1 != NULL);
    assert(pcs2 != NULL);
    if (*pcs2 == '\0') return (char*)pcs1;
    while ((*pcs1 != '\0') && (*pcs2 != '\0')) {
        if (*pcs1 != *pcs2) {
           i = 0;
           break;
        }
        pcs1++;
        pcs2++;
    }
    if (i)
}