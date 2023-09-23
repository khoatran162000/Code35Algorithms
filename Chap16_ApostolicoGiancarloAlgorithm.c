// Apostolico-Giancarlo Algorithm

#define XSIZE 256

void AG(char *x, int m, char *y, int n)
{
    int i, j, k, s, shift, bmGs[XSIZE], skip[XSIZE], suff[XSIZE], bmBc[XSIZE];

    // Preprocessing
    preBmGs(x, m, bmGs, suff);
    preBmBc(x, m, bmBc);
    memset(skip, 0, m * sizeof(int));

    // Searching
    j = 0;
    while (j <= n - m)
    {
        i = m - 1;
        while (i >= 0)
        {
            k = skip[i];
            s = suff[i];
            if (k > 0)
                if (k > s)
                {
                    if (i + 1 == s)
                        i = (-1);
                    else
                        i -= s;
                    break;
                }
                else
                {
                    i -= k;
                    if (k < s)
                        break;
                }
            else
            {
                if (x[i] == y[i + j])
                    --i;
                else
                    break;
            }
        }
        if (i < 0)
        {
            OUTPUT(j);
            skip[m - 1] = m;
            shift = bmGs[0];
        }
        else
        {
            skip[m - 1] = m - 1 - i;
            shift = MAX(bmGs[i], bmBc[y[i + j]] - m + 1 + i);
        }
        j += shift;
        memcpy(skip, skip + shift, (m - shift) * sizeof(int));
        memset(skip + m - shift, 0, shift * sizeof(int));
    }
}