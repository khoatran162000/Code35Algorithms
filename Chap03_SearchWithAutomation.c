// Search with an automation

#include <stdio.h>

struct _graph
{
    int vertexNumber,
        edgeNumber,
        vertexCounter,
        initial,
        *terminal,
        *target,
        *suffixLink,
        *length,
        *position,
        *shift;
};
typedef struct _graph *Graph;

#define ASIZE 256

void preAut(char *x, int m, Graph aut)
{
    int i, state, target, oldTarget;

    for (state = getInitial(aut), i = 0; i < m; ++i)
    {
        oldTarget = getTarget(aut, state, x[i]);
        target = newVertex(aut);
        setTarget(aut, state, x[i], target);
        copyVertex(aut, target, oldTarget);
        state = target;
    }
    setTerminal(aut, state);
}

void AUT(char *x, int m, char *y, int n)
{
    int j, state;
    Graph aut;

    // Preprocessing
    aut = newAutomation(m + 1, (m + 1) * ASIZE);
    preAut(x, m, aut);

    // Searching
    for (state = getInitial(aut), j = 0; j < n; ++j)
    {
        state = getTarget(aut, state, y[j]);
        if (isTerminal(aut, state))
        {
            OUTPUT(j - m + 1);
        }
    }
}