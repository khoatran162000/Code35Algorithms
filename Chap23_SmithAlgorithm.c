// Smith Algorithm

#define ASIZE 256

void SMITH(char *x, int m, char *y, int n)
{
    int j, bmBc[ASIZE], qsBc[ASIZE];

    // Preprocessing
    preBmBc(x, m, bmBc);
    preQsBc(x, m, qsBc);

    // Searching
    j = 0;
    while (j <= n - m)
    {
        if (memcmp(x, y + j, m) == 0)
            OUTPUT(j);
        j += MAX(bmBc[y[j + m - 1]], qsBc[y[j + m]]);
    }
}