#include "StringPatternMatching.h"
#include <string.h>

int StringPatternMatching::match(const char* p, const char* t)
{
    // p: substring to find
    // t: string to search
    int i, j; // counters
    int plen, tlen; // string lengths

    plen = strlen(p);
    tlen = strlen(t);

    for (i = 0; i <= (tlen - plen); ++i) {
        j = 0;
        while ((j < plen) && (t[i + j] == p[j])) {
            j = j + 1;
        }
        if (j == plen) {
            return (i);
        }
    }
    return (-1);
}
