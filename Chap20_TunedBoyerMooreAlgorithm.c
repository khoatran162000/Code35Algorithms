// Tuned Boyer-Moore Algorithm

#define ASIZE 256

void TUNEDBM(char *x, int m, char *y, int n)
{
    int j, k, shift, bmBc[ASIZE];

    // Preprocessing
    preBmBc(x, m, bmBc);
    shift = bmBc[x[m - 1]];
    bmBc[x[m - 1]] = 0;
    memset(y + n, x[m - 1], m);

    // Searching
    j = 0;
    while (j < n)
    {
        k = bmBc[y[j + m - 1]];
        while (k != 0)
        {
            j += k;
            k = bmBc[y[j + m - 1]];
            j += k;
            k = bmBc[y[j + m - 1]];
            j += k;
            k = bmBc[y[j + m - 1]];
        }
        if (memcmp(x, y + j, m - 1) == 0 && j < n)
            OUTPUT(j);
        j += shift; // shift
    }
}