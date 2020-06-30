/**
 * Title   : Merge two binary Max heaps
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap/0
 **/

#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int idx) {
    int lc = 2 * idx + 1;
    int rc = 2 * idx + 2;
    int maxIdx = idx;
    if (lc < n && arr[lc] > arr[idx])
        maxIdx = lc;
    if (rc < n && arr[rc] > arr[maxIdx])
        maxIdx = rc;

    if (maxIdx != idx) {
        swap(arr[idx], arr[maxIdx]);
        heapify(arr, n, maxIdx);
    }
}

void buildMaxHeap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);
}

void mergeHeaps(int merged[], int a[], int b[], int n, int m) {
    for (int i = 0; i < n; ++i)
        merged[i] = a[i];
    for (int i = 0; i < m; ++i)
        merged[n + i] = b[i];
    buildMaxHeap(merged, n + m);
}

int main() {

    int t;
    cin >> t;
    while (t--) {

    int n, m;
    cin >> n >> m;

    int a[n], b[m], merged[n + m];

    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];

    mergeHeaps(merged, a, b, n, m);

    for (int i = 0; i < n + m; ++i)
        cout << merged[i] << " ";
    cout << '\n';

    }
    return 0;
}
