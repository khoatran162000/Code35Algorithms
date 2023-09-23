// Quick Search Algorithm

#define ASIZE 256

void preQsBc(char *x, int m, int qsBc[])
{
    int i;

    for (i = 0; i < ASIZE; ++i)
        qsBc[i] = m + 1;
    for (i = 0; i < m; ++i)
        qsBc[x[i]] = m - i;
}

void QS(char *x, int m, char *y, int n)
{
    int j, qsBc[ASIZE];

    // Preprocessing
    preQsBc(x, m, qsBc);

    // Searching
    j = 0;
    while (j <= n - m)
    {
        if (memcmp(x, y + j, m) == 0)
            OUTPUT(j);
        j += qsBc[y[j + m]]; // shift
    }
}