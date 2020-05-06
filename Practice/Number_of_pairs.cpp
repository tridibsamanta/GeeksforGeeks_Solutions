/**
 * Title   : Number of pairs
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/number-of-pairs/0
 **/

#include<bits/stdc++.h>
using namespace std;

int elementPairCount(int val, int b[], int m, int exc[]) {

    if (val == 0)
        return 0;
    if (val == 1)
        return exc[0];

    int *ub = upper_bound(b, b + m, val);
    int total = (b + m) - ub;

    total += (exc[0] + exc[1]);

    if (val == 2)
        total -= (exc[3] + exc[4]);

    if (val == 3)
        total += exc[2];

    return total;
}

long int countPairs(int a[], int b[], int n, int m) {

    int exc[5] = {0}; // storing number of 0,1,2,3,4 in array 2
    for (int i =0; i < m; ++i)
        if (b[i] < 5)
            ++exc[b[i]];

    sort(b, b + m);

    long int pair_count = 0;

    for (int i = 0; i < n; ++i)
        pair_count += elementPairCount(a[i], b, m, exc);

    return pair_count;
}

int main() {

    int T;
    cin >> T;
    while (T--) {
    int n,m;
    cin >> n >> m;

    int a[n], b[m];

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < m; ++i)
        cin >> b[i];

    long int res = countPairs(a, b, n, m);

    cout << res << "\n";

    }

    return 0;
}
