// Maximal Shift Algorithm
#define ASIZE 256
#define XSIZE 256

typedef struct patternScanOrder
{
    int loc;
    char c;
} pattern;
int minShift[XSIZE];
/* Computation of the MinShift table values. */
void computeMinShift(char *x, int m)
{
    int i, j;
    for (i = 0; i < m; ++i)
    {
        for (j = i - 1; j >= 0; --j)
            if (x[i] == x[j])
                break;
        minShift[i] = i - j;
    }
}
/* Maximal Shift pattern comparison function. */
int maxShiftPcmp(pattern *pat1, pattern *pat2)
{
    int dsh;
    dsh = minShift[pat2->loc] - minShift[pat1->loc];
    return (dsh ? dsh : (pat2->loc - pat1->loc));
}
/* Maximal Shift string matching algorithm. */
void MS(char *x, int m, char *y, int n)
{
    int i, j, qsBc[ASIZE], adaptedGs[XSIZE];
    pattern pat[XSIZE];
    /* Preprocessing */
    computeMinShift(x, m);
    orderPattern(x, m, maxShiftPcmp, pat);
    preQsBc(x, m, qsBc);
    preAdaptedGs(x, m, adaptedGs, pat);
    /* Searching */
    j = 0;
    while (j <= n - m)
    {
        i = 0;
        while (i < m && pat[i].c == y[j + pat[i].loc])
            ++i;
        if (i >= m)
            OUTPUT(j);
        j += MAX(adaptedGs[i], qsBc[y[j + m]]);
    }
}
