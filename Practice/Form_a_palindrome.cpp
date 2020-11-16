/**
 * Title   : Form a palindrome
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/form-a-palindrome/0
 **/

#include<bits/stdc++.h>
using namespace std;

int dp[101][101];

int getMinInsertions(string X, int n) {

    string Y = "";
    for (int i = n - 1; i >= 0; --i)
        Y.push_back(X[i]);

    for (int i = 0; i < n + 1; ++i)
        dp[i][0] = dp[0][i] = 0;

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    return n - dp[n][n];
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;

        int min_insertions = getMinInsertions(str, str.length());
        cout << min_insertions << '\n';
    }

    return 0;
}
