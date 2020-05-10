/**
 * Title   : Reverse array in groups
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/reverse-array-in-groups/0
 **/

#include<iostream>
using namespace std;

void reverseArrayInGroups(long int arr[], int n, int k) {
    for (int i = 0; i < n; i += k) {
        int idx1 = i, idx2;
        idx2 = min(i + (k - 1), n-1);
        while (idx1 < idx2) {
            swap(arr[idx1++], arr[idx2--]);
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        long int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        reverseArrayInGroups(arr, n, k);
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << '\n';
    }
}
