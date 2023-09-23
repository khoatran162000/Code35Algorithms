// Apostolico-Crochemore Algorithm

#define XSIZE 256

void AXAMAC(char *x, int m, char *y, int n)
{
    int i, j, k, ell, kmpNext[XSIZE];

    // Preprocessing
    preKmp(x, m, kmpNext);
    for (ell = 1; x[ell - 1] == x[ell]; ell++)
        ;
    if (ell = m)
        ell = 0;

    // Searching
    i = ell;
    j = k = 0;
    while (j <= n - m)
    {
        while (i < m && x[i] == y[i + j])
            ++i;
        if (i >= m)
        {
            while (k < ell && x[k] == y[j + k])
                ++k;
            if (k >= ell)
                OUTPUT(j);
        }
        j += (i - kmpNext[i]);
        if (i == ell)
            k = MAX(0, k - 1);
        else if (kmpNext[i] <= ell)
        {
            k = MAX(0, kmpNext[i]);
            i = ell;
        }
        else
        {
            k = ell;
            i = kmpNext[i];
        }
    }
}