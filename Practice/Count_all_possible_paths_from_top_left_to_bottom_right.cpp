/**
 * Title   : Count all possible paths from top left to bottom right
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right/0
 **/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int dp[105][105];

// ***** BOTTOM-UP (Tabulation) Approach *****/

long long  numberOfPaths(int m, int n)
{
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= m; ++i)
        dp[i][1] = 1;
    for (int i = 0; i <= n; ++i)
        dp[1][i] = 1;

    for (int i = 2; i <= m; ++i) {
        for (int j = 2; j <= n; ++j) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[m][n];
}

// ***** TOP-DOWN (Memoization) Approach *****/
/*
long long numberOfPathsUtil(int m, int n) {

    if (m == 1 || n == 1)
        return 1;

    if (dp[m][n] != -1)
        return dp[m][n];

    return dp[m][n] = (numberOfPathsUtil(m - 1, n) + numberOfPathsUtil(m, n - 1)) % MOD;
}

long long  numberOfPaths(int m, int n)
{
    memset(dp, -1, sizeof(dp));
    long long res = numberOfPathsUtil(m, n);
    return res;
}
*/

int main() {

    int t;
    cin >> t;
    while (t--) {

        int m, n;
        cin >> m >> n;

        long long paths = numberOfPaths(m, n);
        cout << paths << '\n';
    }

    return 0;
}
