/**
 * Title   : Next Permutation
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/next-permutation/0
 **/

#include<bits/stdc++.h>
using namespace std;

bool nextPermutation(int arr[], int n) {

    if (n == 0)
        return false;

    int i;
    for (i = n - 2; i >= 0; --i) {
        if (arr[i] < arr[i + 1])
            break;
    }

    if (i < 0)
        return false;

    for (int j = n - 1; j > i; --j) {
        if (arr[j] > arr[i]) {
            swap(arr[j], arr[i]);
            break;
        }
    }

    reverse(arr + i + 1, arr + n);

    return true;
}

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        if (!nextPermutation(arr, n))
            sort(arr, arr + n);

        for (int i = 0; i < n; ++i)
            cout << arr[i] << ' ';
        cout << '\n';

    }

    return 0;
}
