// Not So Naive Algorithm

void NSN(char *x, int m, char *y, int n) {
    int j, k, ell;

    // Preprocessing
    if (x[0] == x[1]) {
        k = 2;
        ell = 1;
    }
    else {
        k = 1;
        ell = 2;
    }

    // Searching
    j = 0;
    while (j <= n - m)
        if (x[1] != y[j + 1])
            j += k;
        else {
            if (memcmp(x + 2, y + j + 2, m - 2) == 0 && x[0] == y[j])
                OUTPUT(j);
            j += ell;
        }
}