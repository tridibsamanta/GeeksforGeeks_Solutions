/**
 * Title   : Queries on Strings
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/queries-on-strings/0
 **/

#include<bits/stdc++.h>
using namespace std;

int dp[10005][26];

void constructDPtable(string s) {
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < 26; ++j) {
            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
            }
        }
        dp[i][s[i] - 'a']++;
    }
}

int findDistinctCharacters(int l, int r) {

    int count = 0;
    --l; --r;

    for (int i = 0; i < 26; ++i) {
        if (l > 0) {
            if (dp[r][i] - dp[l - 1][i] > 0)
                ++count;
        }
        else {
            if (dp[r][i] > 0)
                ++count;
        }
    }

    return count;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        memset(dp, 0, sizeof(dp));

        string s;
        cin >> s;

        constructDPtable(s);

        int q;
        cin >> q;

        while (q--) {

            int l, r;
            cin >> l >> r;

            int count = findDistinctCharacters(l, r);
            cout << count << ' ';
        }

        cout << '\n';
    }

    return 0;
}
