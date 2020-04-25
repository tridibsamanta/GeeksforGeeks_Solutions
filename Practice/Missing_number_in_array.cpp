/**
 * Title   : Missing number in array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/missing-number-in-array/0
 **/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

        int n;
        cin >> n;

        vector<int> a(n-1);

        for (int i = 0; i < n-1; ++i)
            cin >> a[i];

        /* Using the XOR technique */

        int x1 = a[0], x2 = 1;

        for (int i = 1; i < n-1; ++i)
            x1 = x1 ^ a[i];

        for (int i = 2; i <= n; ++i)
            x2 = x2 ^ i;

        cout << (x1 ^ x2) << "\n";

    }

}
