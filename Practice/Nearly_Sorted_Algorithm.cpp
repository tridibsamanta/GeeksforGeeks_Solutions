/**
 * Title   : Nearly Sorted Algorithm
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/nearly-sorted-algorithm/0
 **/

#include<bits/stdc++.h>
using namespace std;

void sortKSortedArray(int arr[], int n, int k) {

    priority_queue<int, vector<int>, greater<int> > minheap;

    for (int i = 0; i < k + 1; ++i)
        minheap.emplace(arr[i]);

    int pos = 0;

    for (int i = k + 1; i < n; ++i) {
        arr[pos++] = minheap.top();
        minheap.pop();
        minheap.emplace(arr[i]);
    }

    while (!minheap.empty()) {
        arr[pos++] = minheap.top();
        minheap.pop();
    }

    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        sortKSortedArray(arr, n, k);
        cout << '\n';
    }

    return 0;
}

// T.C. - O(n log k)
// S.C. - O(k)
