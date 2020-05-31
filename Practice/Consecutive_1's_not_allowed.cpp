/**
 * Title   : Consecutive 1's not allowed
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/consecutive-1s-not-allowed/0
 **/

#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int getCount(int n) {

    int a[n], b[n];

    // Base Case
    a[0] = 1;
    b[0] = 1;

    for (int i = 1; i < n; ++i) {
        a[i] = (a[i - 1] + b[i - 1]) % MOD;
        b[i] = a[i - 1];
    }

    return (a[n - 1] + b[n - 1]) % MOD;
}

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

    int n;
    cin >> n;

    int res = getCount(n);
    cout << res << '\n';

    }

    return 0;
}
