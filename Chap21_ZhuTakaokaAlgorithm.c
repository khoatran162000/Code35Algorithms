// Zhu-Takaoka Algorithm

#define XSIZE 256
#define ASIZE 256

void preZtBc(char *x, int m, int ztBc[ASIZE][ASIZE])
{
    int i, j;

    for (i = 0; i < ASIZE; ++i)
        for (j = 0; j < ASIZE; ++j)
            ztBc[i][j] = m;
    for (i = 0; i < ASIZE; ++i)
        ztBc[i][x[0]] = m - 1;
    for (i = 1; i < m - 1; ++i)
        ztBc[x[i - 1]][x[i]] = m - 1 - i;
}

void ZT(char *x, int m, char *y, int n)
{
    int i, j, ztBc[ASIZE][ASIZE], bmGs[XSIZE];

    // Preprocessing
    preZtBc(x, m, ztBc);
    preBmGs(x, m, bmGs);

    // Searching
    j = 0;
    while (j <= n - m)
    {
        i = m - 1;
        while (i < m && x[i] == y[i + j])
            --i;
        if (i < 0)
        {
            OUTPUT(j);
            j += bmGs[0];
        }
        else
            j += MAX(bmGs[i], ztBc[y[j + m - 2]][y[j + m - 1]]);
    }
}