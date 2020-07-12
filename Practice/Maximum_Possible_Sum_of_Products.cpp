/**
 * Title   : Maximum Possible Sum of Products
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/maximum-possible-sum-of-products/0
 **/

#include<bits/stdc++.h>
using namespace std;

void maxSumProduct(int a[], int b[], int n) {

    sort(a, a + n, greater<int>());
    sort(b, b + n, greater<int>());

    int maxSum = 0;

    for (int i = 0; i < n; ++i)
        maxSum += a[i] * b[i];

    cout << maxSum;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        int a[n], b[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        for (int i = 0; i < n; ++i)
            cin >> b[i];

        maxSumProduct(a, b, n);
        cout << '\n';

    }

    return 0;
}
