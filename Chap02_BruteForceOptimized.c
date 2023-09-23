// More efficient Brute Force

#define EOS '\0'

void BF(char *x, int m, char *y, int n)
{
    char *yb;

    // Searching
    for (yb = y; *y != EOS; ++y)
    {
        if (memcmp(x, y, m) == 0)
        {
            OUTPUT(y - yb);
        }
    }
}