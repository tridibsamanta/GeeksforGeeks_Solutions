/**
 * Title   : Maximum Index
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/maximum-index/0
 **/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll findMaxDiff(ll arr[], ll n) {

    ll *leftMin = (ll*)malloc(n * sizeof(ll));
    ll *rightMax = (ll*)malloc(n * sizeof(ll));

    leftMin[0] = arr[0];
    for (ll i = 1; i < n; ++i)
        leftMin[i] = min(arr[i], leftMin[i - 1]);

    rightMax[n - 1] = arr[n - 1];
    for (ll i = n - 2; i >= 0; --i)
        rightMax[i] = max(arr[i], rightMax[i + 1]);

    ll maxDiff = -1, i = 0, j = 0;
    while (i < n && j < n) {
        if (leftMin[i] <= rightMax[j]) {
            maxDiff = max(maxDiff, j - i);
            ++j;
        }
        else
            ++i;
    }

    delete[] leftMin;
    delete[] rightMax;

    return maxDiff;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        ll *arr = (ll*)malloc(n*sizeof(ll));
        for (ll i = 0; i < n; ++i)
            cin >> arr[i];
        ll res = findMaxDiff(arr, n);
        cout << res << '\n';
    }
    return 0;
}

/*
 ~ Time Complexity   : O(n)
 ~ Space Complexity  : O(n)
*/
