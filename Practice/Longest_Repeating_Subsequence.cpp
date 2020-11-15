/**
 * Title   : Longest Repeating Subsequence
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
 **/

#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int longestRepeatingSubsequence(string X, int n) {

    string Y = X;

    for (int i = 0; i < n + 1; ++i)
        dp[i][0] = dp[0][i] = 0;

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (X[i - 1] == Y[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return dp[n][n];
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        string str;
        cin >> str;

        int len = longestRepeatingSubsequence(str, n);
        cout << len << '\n';
    }

    return 0;
}
