// Forward Dawg Matching Algorithm
int FDM(char *x, int m, char *y, int n) {
    int j, init, ell, state;
    Graph aut;

    // Preprocessing
    aut = newSuffixAutomaton(2*(m+2), 2*(m+2)*ASIZE);
    buildSuffixAutomaton(x, m, aut);
    init = getInitial(aut);

    // Searching
    ell = 0;
    state = init;
    for (j = 0; j < n; ++j) {
        if (getTarget(aut, state, y[j]) != UNDEFINED) {
            ++ell;
            state = getTarget(aut, state, y[j]);
        }
        else {
            while (state != init && getTarget(aut, state, y[j]) == UNDEFINED)
                state = getSuffixLink(aut, state);
            if (getTarget(aut, state, y[j]) != UNDEFINED) {
                ell = getLength(aut, state) + 1;
                state = getTarget(aut, state, y[j]);
            }
            else {
                ell = 0;
                state = init;
            }
        }
        if (ell == m)
            OUTPUT(j - m + 1);
    }
}