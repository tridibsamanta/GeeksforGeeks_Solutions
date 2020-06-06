/**
 * Title   : Longest Palindrome in a String
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0
 **/

#include<bits/stdc++.h>
using namespace std;

void findLongestPalindromicSubstring(string s) {

    int n = s.length();

    bool dp[n][n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; ++i)
        dp[i][i] = true;

    int startIdx = 0, maxLen = 1, flag = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == s[i + 1])  {
            dp[i][i+1] = true;
            if (!flag) {
                startIdx = i;
                maxLen = 2;
                ++flag;
            }
        }
    }

    for (int k = 3; k <= n; ++k) {

        for (int i = 0; i <= n - k; ++i) {

            int j = i + k - 1;

            if (s[i] == s[j] && dp[i+1][j-1]) {
                dp[i][j] = true;
                if (k > maxLen) {
                    maxLen = k;
                    startIdx = i;
                }
            }
        }
    }

    for (int i = startIdx; i < startIdx + maxLen; ++i)
        cout << s[i];

}


int main() {

    int t;
    cin >> t;
    while (t--) {

        string s;
        cin >> s;

        findLongestPalindromicSubstring(s);
        cout << '\n';
    }

    return 0;
}
