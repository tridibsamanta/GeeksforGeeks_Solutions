/**
 * Title   : Longest Common Substring
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/longest-common-substring/0
 **/

#include<bits/stdc++.h>
using namespace std;

int dp[105][105];

int longestCommonSubstring(string str1, string str2, int m, int n) {

    for (int i = 0; i < n + 1; ++i)
        dp[0][i] = 0;
    for (int i = 0; i < m + 1; ++i)
        dp[i][0] = 0;

    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0;
        }
    }

    int maxLen = 0;

    for (int i = 1; i < m + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            maxLen = max(maxLen, dp[i][j]);
        }
    }

    return maxLen;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int N, M;
        cin >> N >> M;

        string X, Y;
        cin >> X >> Y;

        int len = longestCommonSubstring(X, Y, N, M);
        cout << len << '\n';
    }

    return 0;
}
