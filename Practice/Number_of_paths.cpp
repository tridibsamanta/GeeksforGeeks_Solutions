/**
 * Title   : Number of paths
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/number-of-paths0926/1
 **/

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

int dp[1001][1001];

// ***** BOTTOM-UP (Tabulation) Approach *****/

/*
long long  numberOfPaths(int m, int n)
{
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= m; ++i)
        dp[i][1] = 1;
    for (int i = 0; i <= n; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m][n];
}
*/

// ***** TOP-DOWN (Memoization) Approach *****/

long long numberOfPathsUtil(int m, int n) {

    if (m == 1 || n == 1)
        return 1;

    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = numberOfPathsUtil(m - 1, n) + numberOfPathsUtil(m, n - 1);
}

long long  numberOfPaths(int m, int n)
{
    memset(dp, -1, sizeof(dp));
    long long res = numberOfPathsUtil(m, n);
    return res;
}


// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>m>>n;
	    cout << numberOfPaths(m, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
