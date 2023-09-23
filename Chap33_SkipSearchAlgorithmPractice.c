// Skip Search Algorithm in Practice
#include <stdio.h>

#define ASIZE 256
#define XSIZE 256

struct _cell
{
    int element;
    struct _cell *next;
};
typedef struct _cell *List;

void SKIP(char *x, int m, char *y, int n)
{
    int i, j;
    List ptr, z[ASIZE];
    /* Preprocessing */
    memset(z, NULL, ASIZE * sizeof(List));
    for (i = 0; i < m; ++i)
    {
        ptr = (List)malloc(sizeof(struct _cell));
        if (ptr == NULL)
            error("SKIP");
        ptr->element = i;
        ptr->next = z[x[i]];
        z[x[i]] = ptr;
    }
    /* Searching */
    for (j = m - 1; j < n; j += m)
        for (ptr = z[y[j]]; ptr != NULL; ptr = ptr->next)
            if (memcmp(x, y + j - ptr->element, m) == 0)
                OUTPUT(j - ptr->element);
}
