// Reverse Factor Algorithm
#include <stdio.h>

#define ASIZE 256

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
typedef int boolean;
#define UNDEFINED -1
/* returns a new data structure for
a graph with v vertices and e edges */
Graph newGraph(int v, int e)
{
    Graph g;
    g = (Graph)calloc(1, sizeof(struct _graph));
    if (g == NULL)
        error("newGraph");
    g->vertexNumber = v;
    g->edgeNumber = e;
    g->initial = 0;
    g->vertexCounter = 1;
    return (g);
}

void buildSuffixAutomaton(char *x, int m, Graph aut)
{
    int i, art, init, last, p, q, r;
    char c;
    init = getInitial(aut);
    art = newVertex(aut);
    setSuffixLink(aut, init, art);
    last = init;
    for (i = 0; i < m; ++i)
    {
        c = x[i];
        p = last;
        q = newVertex(aut);
        setLength(aut, q, getLength(aut, p) + 1);
        setPosition(aut, q, getPosition(aut, p) + 1);
        while (p != init &&
               getTarget(aut, p, c) == UNDEFINED)
        {
            setTarget(aut, p, c, q);
            setShift(aut, p, c, getPosition(aut, q) - getPosition(aut, p) - 1);
            p = getSuffixLink(aut, p);
        }
        if (getTarget(aut, p, c) == UNDEFINED)
        {
            setTarget(aut, init, c, q);
            setShift(aut, init, c,
                     getPosition(aut, q) -
                         getPosition(aut, init) - 1);
            setSuffixLink(aut, q, init);
        }
        else if (getLength(aut, p) + 1 ==
                 getLength(aut, getTarget(aut, p, c)))
            setSuffixLink(aut, q, getTarget(aut, p, c));
        else
        {

            r = newVertex(aut);
            copyVertex(aut, r, getTarget(aut, p, c));
            setLength(aut, r, getLength(aut, p) + 1);
            setSuffixLink(aut, getTarget(aut, p, c), r);
            setSuffixLink(aut, q, r);
            while (p != art &&
                   getLength(aut, getTarget(aut, p, c)) >=
                       getLength(aut, r))
            {
                setShift(aut, p, c,
                         getPosition(aut,
                                     getTarget(aut, p, c)) -
                             getPosition(aut, p) - 1);
                setTarget(aut, p, c, r);
                p = getSuffixLink(aut, p);
            }
        }
        last = q;
    }
    setTerminal(aut, last);
    while (last != init)
    {
        last = getSuffixLink(aut, last);
        setTerminal(aut, last);
    }
}
char *reverse(char *x, int m)
{
    char *xR;
    int i;
    xR = (char *)malloc((m + 1) * sizeof(char));
    for (i = 0; i < m; ++i)
        xR[i] = x[m - 1 - i];
    xR[m] = '\0';
    return (xR);
}
int RF(char *x, int m, char *y, int n)
{
    int i, j, shift, period, init, state;
    Graph aut;
    char *xR;
    /* Preprocessing */
    aut = newSuffixAutomaton(2 * (m + 2), 2 * (m + 2) * ASIZE);
    xR = reverse(x, m);
    buildSuffixAutomaton(xR, m, aut);
    init = getInitial(aut);
    period = m;
    /* Searching */
    j = 0;
    while (j <= n - m)
    {
        i = m - 1;
        state = init;
        shift = m;
        while (i + j >= 0 &&
               getTarget(aut, state, y[i + j]) !=
                   UNDEFINED)
        {
            state = getTarget(aut, state, y[i + j]);
            if (isTerminal(aut, state))
            {
                period = shift;
                shift = i;
            }
            --i;
        }
        if (i < 0)
        {
            OUTPUT(j);
            shift = period;
        }
        j += shift;
    }
}