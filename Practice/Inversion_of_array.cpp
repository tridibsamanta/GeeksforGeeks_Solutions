/**
 * Title   : Inversion of array
 * Author  : Tridib Samanta
 * Link    : https://practice.geeksforgeeks.org/problems/inversion-of-array/0
 **/

#include<iostream>
using namespace std;

long int mergeArrays(long int *arr, long int *L, long int L_len, long int *R, long int R_len) {

    long int i = 0, j = 0, k = 0;
    long int invCount = 0;

    while (i < L_len && j < R_len) {

        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else {
            arr[k++] = R[j++];
            invCount = invCount + (L_len - i);
        }
    }

    while (i < L_len)
        arr[k++] = L[i++];

    while (j < R_len)
        arr[k++] = R[j++];

    return invCount;
}

long int mergeSort(long int arr[], long int n) {

    long int mid, invCount = 0;

    if (n > 1) {
    mid = n / 2;

    long int* L = new long int[mid];
    long int* R = new long int[n - mid];

    for (long int i = 0; i < mid; ++i)
        L[i] = arr[i];
    for (long int i = mid; i < n; ++i)
        R[i - mid] = arr[i];

    invCount += mergeSort(L, mid);
    invCount += mergeSort(R, n - mid);
    invCount += mergeArrays(arr, L, mid, R, n - mid);

    delete L;
    delete R;
    }
    return invCount;
}

int main() {

    int T; cin >> T;
    while (T--) {

    long int n;
    cin >> n;

    long int arr[n];
    for (long int i = 0; i < n; ++i)
        cin >> arr[i];

    long int ans = mergeSort(arr, n);
    cout << ans << "\n";

    }

    return 0;
}
