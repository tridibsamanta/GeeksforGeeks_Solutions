/**
 * Title   : Subset with no pair sum divisible by K
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/subset-with-no-pair-sum-divisible-by-k/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        //To store the freq of remainders
        vector<int> f(k, 0);
        for (int i = 0; i < n; ++i)
            f[a[i] % k]++;

        //if k is even, we can't have nos with k/2 rem. more than once in the subset
        if (k % 2 == 0)
            f[k / 2] = min(f[k / 2], 1);

        //Also we cant have nos with rem. 0 more than once in the subset
        int res = min(f[0], 1);

        for (int i = 1; i <= k / 2; ++i)
            res += max(f[i], f[k - i]);

        cout << res << '\n';
    }

    return 0;
}