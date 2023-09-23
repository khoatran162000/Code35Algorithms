// Berry-Ravindran Algorithm

#define ASIZE 256

void preBrBc(char *x, int m, int brBc[ASIZE][ASIZE])
{
    int a, b, i;

    for (a = 0; a < ASIZE; ++a)
        for (b = 0; b < ASIZE; ++b)
            brBc[a][b] = m + 2;
    for (a = 0; a < ASIZE; ++a)
        brBc[a][x[0]] = m + 1;
    for (i = 0; i < m - 1; ++i)
        brBc[x[i]][x[i + 1]] = m - i;
    for (a = 0; a < ASIZE; ++a)
        brBc[x[m - 1]][a] = 1;
}

void BR(char *x, int m, char *y, int n)
{
    int j, brBc[ASIZE][ASIZE];

    // Preprocessing
    preBrBc(x, m, brBc);

    // Searching
    y[n + 1] = '\0';
    j = 0;
    while (j <= n - m)
    {
        if (memcmp(x, y + j, m) == 0)
            OUTPUT(j);
        j += brBc[y[j + m]][y[j + m + 1]];
    }
}