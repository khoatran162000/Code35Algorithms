// Raita Algorithm

#define ASIZE 256

void RAITA(char *x, int m, char *y, int n)
{
    int j, bmBc[ASIZE];
    char c, firstCh, *secondCh, middleCh, lastCh;

    // Preprocessing
    preBmBc(x, m, bmBc);
    firstCh = x[0];
    secondCh = x + 1;
    middleCh = x[m / 2];
    lastCh = x[m - 1];

    // Searching
    j = 0;
    while (j <= n - m)
    {
        c = y[j + m - 1];
        if (lastCh == c && middleCh == y[j + m / 2] && firstCh == y[j] && memcmp(secondCh, y + j + 1, m - 2) == 0)
            OUTPUT(j);
        j += bmBc[c];
    }
}