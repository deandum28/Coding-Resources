// LCA - Lowest common ancestor 
// Implementation O(sqrt(n))
void DF(int n, int t2, int lev)
{
    int i;
    T2[n] = t2, Lev[n] = lev;
    if (lev % H == 0) t2 = n;
    for (i = 0; i < N; i++)
        if (T[i] == n) DF(i, t2, lev+1);
}

int LCA(int x, int y)
{
    while (T2[x] != T2[y])
        if (Lev[x] > Lev[y])
            x = T2[x];
        else
            y = T2[y];
    while (x != y)
        if (Lev[x] > Lev[y])
            x = T[x];
        else
            y = T[y];
    return x;
}

