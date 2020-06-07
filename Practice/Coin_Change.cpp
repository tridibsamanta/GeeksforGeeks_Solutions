/**
 * Title   : Coin Change
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/coin-change/0
 **/

#include<bits/stdc++.h>
using namespace std;

int coinChangeWays(vector<int> coins, int amt) {

    vector<int> dp(amt + 1, 0);

    dp[0] = 1;

    for (int i = 0; i < coins.size(); ++i)
        for (int j = coins[i]; j <= amt; ++j)
            dp[j] += dp[j - coins[i]];

    return dp[amt];
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int c;
        cin >> c;

        vector<int> coins(c);
        for (int i = 0; i < c; ++i)
            cin >> coins[i];

        int amt;
        cin >> amt;

        int res = coinChangeWays(coins, amt);
        cout << res << '\n';
    }

    return 0;
}
