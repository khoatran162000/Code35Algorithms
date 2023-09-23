// Simon Algorithm
#include <stdio.h>

#define XSIZE 256
struct _cell
{
    int element;
    struct _cell *next;
};
typedef struct _cell *List;

int getTransition(char *x, int m, int p, List L[], char c)
{
    List cell;

    if (p < m - 1 && x[p + 1] == c)
        return (p + 1);
    else if (p > -1)
    {
        cell = L[p];
        while (cell != NULL)
            if (x[cell->element] == c)
                return (cell->element);
            else
                cell = cell->next;
        return (-1);
    }
    else
    {
        return (-1);
    }
}

void setTransition(int p, int q, List L[])
{
    List cell;

    cell = (List)malloc(sizeof(struct _cell));
    if (cell == NULL)
        error("SIMON/setTransition");
    cell->element = q;
    cell->next = L[p];
    L[p] = cell;
}

int preSimon(char *x, int m, List L[])
{
    int i, k, ell;
    List cell;

    memset(L, NULL, (m - 2) * sizeof(List));
    ell = -1;
    for (i = 1; i < m; ++i)
    {
        k = ell;
        cell = (ell == 1 ? NULL : L[k]);
        ell = -1;
        if (x[i] == x[k + 1])
            ell = k + 1;
        else
            setTransition(i - 1, k + 1, L);
        while (cell != NULL)
        {
            k = cell->element;
            if (x[i] == x[k])
                ell = k;
            else
                setTransition(i - 1, k, L);
            cell = cell->next;
        }
    }
    return (ell);
}

void SIMON(char *x, int m, char *y, int n)
{
    int j, ell, state;
    List L[XSIZE];

    // Preprocessing
    ell = preSimon(x, m, L);

    // Searching
    for (state = -1, j = 0; j < n; ++j)
    {
        state = getTransition(x, m, state, L, y[j]);
        if (state >= m - 1)
        {
            OUTPUT(j - m + 1);
            state = ell;
        }
    }
}