/*
    C(n,r) mod m
    Using recurrence:
    C(i,k) = C(i-1,k-1) + C(i-1,k)
    Time Complexity: O(n*r)
    Space Complexity: O(n*r)
*/
 
long long C(int n, int r, int MOD)
{
    vector< vector<long long> > C(n+1,vector<long long> (r+1,0));
 
    for (int i=0; i<=n; i++)
    {
        for (int k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i][k] = 1;
            else
                C[i][k] = (C[i-1][k-1] + C[i-1][k])%MOD;
    }
    return C[n][r];
}

/*
    Time Complexity: O(n*r)
    Space Complexity: O(r)
*/
long long C(int n, int r, int MOD)
{
    vector< vector<long long> > C(2,vector<long long> (r+1,0));
 
    for (int i=0; i<=n; i++)
    {
        for (int k=0; k<=r && k<=i; k++)
            if (k==0 || k==i)
                C[i&1][k] = 1;
            else
                C[i&1][k] = (C[(i-1)&1][k-1] + C[(i-1)&1][k])%MOD;
    }
    return C[n&1][r];
}
/*
    Time Complexity: O(k)
    Space Complexity: O(1)
*/

int C(int n, int k)
{
    int res = 1;
 
    // Since C(n, k) = C(n, n-k)
    if ( k > n - k )
        k = n - k;
 
    // Calculate value of [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for (int i = 0; i < k; ++i)
    {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}
