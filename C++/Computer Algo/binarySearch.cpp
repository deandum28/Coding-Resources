int N, A[N];
 
int binary_search(int val)
{
    int i, step;
    for (step = 1; step < N; step <<= 1);
    for (i = 0; step; step >>= 1)
        if (i + step < N && A[i + step] <= val)
           i += step;
    return i;
}