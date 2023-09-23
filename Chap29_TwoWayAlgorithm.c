// Two Way Algorithm

/* Computing of the maximal suffix for <= */
int maxSuf(char *x, int m, int *p)
{
    int ms, j, k;
    char a, b;
    ms = -1;
    j = 0;
    k = *p = 1;
    while (j + k < m)
    {
        a = x[j + k];
        b = x[ms + k];
        if (a < b)
        {
            j += k;
            k = 1;
            *p = j - ms;
        }
        else if (a == b)
            if (k != *p)
                ++k;
            else
            {
                j += *p;
                k = 1;
            }
        else
        { /* a > b */
            ms = j;
            j = ms + 1;
            k = *p = 1;
        }
    }
    return (ms);
}
/* Computing of the maximal suffix for >= */
int maxSufTilde(char *x, int m, int *p)
{
    int ms, j, k;
    char a, b;
    ms = -1;
    j = 0;
    k = *p = 1;
    while (j + k < m)
    {
        a = x[j + k];
        b = x[ms + k];
        if (a > b)
        {
            j += k;
            k = 1;
            *p = j - ms;
        }
        else if (a == b)
            if (k != *p)
                ++k;
            else
            {
                j += *p;
                k = 1;
            }
        else
        { /* a < b */
            ms = j;
            j = ms + 1;
            k = *p = 1;
        }
    }
    return (ms);
}
/* Two Way string matching algorithm. */
void TW(char *x, int m, char *y, int n)
{
    int i, j, ell, memory, p, per, q;
    /* Preprocessing */
    i = maxSuf(x, m, &p);
    j = maxSufTilde(x, m, &q);
    if (i > j)
    {
        ell = i;
        per = p;
    }
    else
    {
        ell = j;
        per = q;
    }
    /* Searching */
    if (memcmp(x, x + per, ell + 1) == 0)
    {
        j = 0;
        memory = -1;
        while (j <= n - m)
        {
            i = MAX(ell, memory) + 1;
            while (i < m && x[i] == y[i + j])
                ++i;
            if (i >= m)
            {
                i = ell;
                while (i > memory && x[i] == y[i + j])
                    --i;
                if (i <= memory)
                    OUTPUT(j);
                j += per;
                memory = m - per - 1;
            }
            else
            {
                j += (i - ell);
                memory = -1;
            }
        }
    }
    else
    {
        per = MAX(ell + 1, m - ell - 1) + 1;
        j = 0;
        while (j <= n - m)
        {
            i = ell + 1;
            while (i < m && x[i] == y[i + j])
                ++i;
            if (i >= m)
            {
                i = ell;
                while (i >= 0 && x[i] == y[i + j])
                    --i;
                if (i < 0)
                    OUTPUT(j);
                j += per;
            }
            else
                j += (i - ell);
        }
    }
}