// Brute Force Algorithm

void BF(char *x, int m, char *y, int n)
{
    int i, j;

    // Searching
    for (j = 0; j <= n - m; ++j)
    {
        for (int i = 0; i < m && x[i] == y[i + j]; ++i)
        {
            if (i >= m)
            {
                OUTPUT(j);
            }
        }
    }
}
