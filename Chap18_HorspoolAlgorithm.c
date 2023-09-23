// Horspool Algorithm

#define ASIZE 256

void HORSPOOL(char *x, int m, char *y, int n)
{
    int j, bmBc[ASIZE];
    char c;

    // Preprocessing
    preBmBc(x, m, bmBc);

    // Searching
    j = 0;
    while (j <= n - m)
    {
        c = y[j + m - 1];
        if (x[m - 1] == c && memcmp(x, y + j, m - 1) == 0)
            OUTPUT(j);
        j += bmBc[c];
    }
}