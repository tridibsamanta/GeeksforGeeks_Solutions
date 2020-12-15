/**
 * Title   : Longest Common Subsequence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1
 **/

// { Driver Code Starts
#include<bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

int lcs(int, int, string, string);

int main()
{
    int t, n, k, x, y;

    cin >> t;
    while (t--)
    {
        cin >> x >> y;      // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;    // Take both the string as input

        cout << lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends

int dp[105][105];

// TOP-DOWN Approach (Memoization)

/*
int lcsCompute(int x, int y, string s1, string s2) {

    if (x == 0 || y == 0)
        return 0;

    if (dp[x][y] != -1)
        return dp[x][y];

    if (s1[x - 1] == s2[y - 1])
        return dp[x][y] = 1 + lcsCompute(x - 1, y - 1, s1, s2);
    else
        return dp[x][y] = max(lcsCompute(x, y - 1, s1, s2), lcsCompute(x - 1, y, s1, s2));
}

int lcs(int x, int y, string s1, string s2){
    memset(dp, -1, sizeof(dp));
    return lcsCompute(x, y, s1, s2);
}
*/

// BOTTOM-UP Approach (Tabulation)

int lcs(int x, int y, string s1, string s2) {

    for (int i = 0; i < x + 1; ++i)
        dp[i][0] = 0;
    for (int i = 0; i < y + 1; ++i)
        dp[0][i] = 0;

    for (int i = 1; i < x + 1; ++i) {
        for (int j = 1; j < y + 1; ++j) {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[x][y];
}