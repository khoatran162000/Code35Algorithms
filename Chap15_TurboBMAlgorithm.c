// Turbo-BM Algorithm

#define XSIZE 256
#define ASIZE 256

void preBmBc(char *x, int m, int bmBc[])
{
    int i;

    for (i = 0; i < ASIZE; ++i)
        bmBc[i] = m;
    for (i = 0; i < m - 1; ++i)
        bmBc[x[i]] = m - i - 1;
}

void preBmGs(char *x, int m, int bmGs[])
{
    int i, j, suff[XSIZE];

    suffixes(x, m, suff);

    for (i = 0; i < m; ++i)
        bmGs[i] = m;
    j = 0;
    for (i = m - 1; i >= -1; --i)
        if (i == -1 || suff[i] == i + 1)
            for (; j < m - 1 - i; ++j)
                if (bmGs[j] == m)
                    bmGs[j] = m - 1 - i;
    for (i = 0; i <= m - 2; ++i)
        bmGs[m - 1 - suff[i]] = m - 1 - i;
}

void TBM(char *x, int m, char *y, int n)
{
    int bcShift, i, j, shift, u, v, turboShift, bmGs[XSIZE], bmBc[ASIZE];

    // Preprocessing
    preBmGS(x, m, bmGs);
    preBmBc(x, m, bmBc);

    // Searching
    j = u = 0;
    shift = m;
    while (j <= n - m)
    {
        i = m - 1;
        while (i >= 0 && x[i] == y[i + j])
        {
            --i;
            if (u != 0 && i == m - 1 - shift)
                i -= u;
        }
        if (i < 0)
        {
            OUTPUT(j);
            shift = bmGs[0];
            u = m - shift;
        }
        else
        {
            v = m - 1 - i;
            turboShift = u - v;
            bcShift = bmBc[y[i + j]] - m + 1 + i;
            shift = MAX(turboShift, bcShift);
            shift = MAX(shift, bmGs[i]);
            if (shift == bmGs[i])
                u = MIN(m - shift, v);
            else
            {
                if (turboShift < bcShift)
                    shift = MAX(shift, u + 1);
                u = 0;
            }
        }
        j += shift;
    }
}