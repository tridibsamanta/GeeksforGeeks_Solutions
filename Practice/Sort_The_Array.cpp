/**
 * Title   : Sort The Array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/sort-the-array/0/
 **/

#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int mid, int r) {

    int n1 = mid - l + 1, n2 = r - mid;

    int dummy1[n1], dummy2[n2];

    for (int i = 0; i < n1; ++i)
        dummy1[i] = arr[l + i];

    for (int i = 0; i < n2; ++i)
        dummy2[i] = arr[mid + 1 + i];

    int idx = l;
    int i = 0, j = 0;

    while (i < n1 && j < n2) {

        if (dummy1[i] > dummy2[j])
            arr[idx++] = dummy2[j++];
        else
            arr[idx++] = dummy1[i++];
    }

    while (i < n1) {
        arr[idx++] = dummy1[i++];
    }

    while (j < n2) {
        arr[idx++] = dummy2[j++];
    }
}

void mergeSort(int arr[], int l, int r) {

    if (l < r) {

        int mid = l + (r - l) / 2;

        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
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

        mergeSort(arr, 0, n-1);

        for (int i = 0; i < n; ++i)
            cout << arr[i] << ' ';

        cout << '\n';
    }

    return 0;

}
