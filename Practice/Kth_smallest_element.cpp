/**
 * Title   : Kth smallest element
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/kth-smallest-element/0
 **/

#include<iostream>
#include<algorithm>
using namespace std;

int findKthSmallestElement(int arr[], int n, int k) {

    sort(arr, arr + n);

    return arr[k-1];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        int k;
        cin >> k;
        int res = findKthSmallestElement(arr, n, k);
        cout << res << '\n';
    }
}
